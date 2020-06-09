#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
���ﶨ���˲�ͬ��Ϸģʽ��������ת��
*/

/**
 * From gameMode.c
 * ������Ϸģʽ����
 */
int GameModeNum = 3;

/**
 * From gameMode.c
 * ������Ϸģʽ����
 */
char* GameModeName[] = {"����ģʽ", "������Ѫ", "��ͽ����"};

/**
 * From gameMode.c
 * ����ģʽ
 */
int ClassGameMode(TIMES* Game, PLAYER* P1, PLAYER* P2)
{
    char IsNext = 'n';
    PLAYER* Winner = NULL;
    unsigned char PunchValue_P1 = 0;
    unsigned char PunchValue_P2 = 0;

    do
    {
        InitPlayerHP(P1, 1, P2, 1);

        ClassModeController(NULL, 3, 3);

        while(1)
        {
            PunchValue_P1 = (unsigned char)getch() - 1 - 48;
            if(PunchValue_P1<0 || PunchValue_P1>2)
                ClassModeController(NULL, 4, 4);
            else
                break;
        }

        PunchValue_P2 = strategy_AI(ThisGame->GameTimes);

        NotePunch(PlayerPunch(PunchValue_P1), P1);
        NotePunch(PlayerPunch(PunchValue_P2), P2);

        Winner = JudgeWinAndLose(Game, P1, PunchValue_P1, P2, PunchValue_P2);
        if(Winner != NULL)
            DeductHP((Winner == P1) ? P2 : P1, 1);

        IsNext = ClassModeController(Winner, PunchValue_P1, PunchValue_P2);
        Game->RoundTimes++;

        NoteGameData(Winner);
        Game->GameTimes++;
    }
    while(IsNext == 'n');

    return 0;
}


/**
 * From gameMode.c
 * ������Ѫģʽ
 */
int ThreeBloodGameMode(TIMES* Game, PLAYER* P1, PLAYER* P2)
{
    char IsNext = 'n';
    PLAYER* Winner = NULL;
    unsigned char PunchValue_P1 = 0;
    unsigned char PunchValue_P2 = 0;

    do
    {
        InitPlayerHP(P1, 3, P2, 3);

        ThreeBloodModeController(NULL, NULL, 3, 3);
        
        do
        {
            while(1)
            {
                PunchValue_P1 = (unsigned char)getch() - 1 - 48;
                if(PunchValue_P1<0 || PunchValue_P1>2)
                    ThreeBloodModeController(NULL, NULL, 4, 4);
                else
                    break;
            }

            PunchValue_P2 = strategy_AI(ThisGame->RoundTimes);

            if(PunchValue_P1<0 || PunchValue_P1>2)
                return 1;

            NotePunch(PlayerPunch(PunchValue_P1), P1);
            NotePunch(PlayerPunch(PunchValue_P2), P2);

            Winner = JudgeWinAndLose(Game, P1, PunchValue_P1, P2, PunchValue_P2);
            if(Winner != NULL)
                DeductHP((Winner == P1) ? P2 : P1, 1);

            Game->RoundTimes++;

            IsNext = ThreeBloodModeController(Winner, (Winner==P1 ? P2 : P1), PunchValue_P1, PunchValue_P2);
        }
        while(P1->HP && P2->HP);

        Game->GameTimes++;
        NoteGameData(Winner);
    }
    while(IsNext == 'n');

    return 0;
}

/**
 * From gameMode.c
 * ��ͽ����ģʽ
 */
int GamblerHellGameMode(TIMES* Game, PLAYER* P1, PLAYER* P2)
{
    char IsNext = 'n';
    PLAYER* Winner = NULL;
    unsigned char PunchValue_P1 = 0;
    unsigned char PunchValue_P2 = 0;

    do
    {
        InitPlayerHP(P1, 10, P2, 10);

        GamblerHellModeController(NULL, NULL, 3, 3);

        do
        {
            while(1)
            {
                PunchValue_P1 = (unsigned char)getch() - 1 - 48;
                if(PunchValue_P1<0 || PunchValue_P1>2)
                    GamblerHellModeController(NULL, NULL, 4, 4);
                else
                    break;
            }

            PunchValue_P2 = strategy_AI(ThisGame->RoundTimes);

            if(PunchValue_P1<0 || PunchValue_P1>2)
                return 1;

            NotePunch(PlayerPunch(PunchValue_P1), P1);
            NotePunch(PlayerPunch(PunchValue_P2), P2);

            Winner = JudgeWinAndLose(Game, P1, PunchValue_P1, P2, PunchValue_P2);
            if(Winner != NULL)
                DeductHP((Winner == P1) ? P2 : P1, (int)(Winner->ThisPunch->PunchValue + 1));

            Game->RoundTimes++;

            IsNext = GamblerHellModeController(Winner, (Winner==P1 ? P2 : P1), PunchValue_P1, PunchValue_P2);
        }
        while(P1->HP>0 && P2->HP>0);

        Game->GameTimes++;
        NoteGameData(Winner);
    }
    while(IsNext == 'n');

    return 0;
}

/**
 * From gameMode.c
 * ������Ϸģʽ��Ӧ�ĺ���ָ��
 */
typedef const int (*GAMEMODE)(TIMES* ,PLAYER* ,PLAYER*);
GAMEMODE GameModes[] = {ClassGameMode, ThreeBloodGameMode, GamblerHellGameMode};


/**
 * From gameMode.c
 * �����Ϸģʽ����
 * 
 * return int ģʽID
 */
int GetGameModeCode(int TmpModeCode)
{
    if(48<=TmpModeCode || TmpModeCode<=51)
        TmpModeCode -= 48;
    else if(TmpModeCode == 13){}
    else
        TmpModeCode = 0;
    
    return TmpModeCode;
}

/**
 * From gameMode.c
 * ѡĳһ��Ϸģʽ
 * 
 * int ModeCode ��Ϸģʽ����
 * 
 * return GAMEMODE* ��Ӧ��Ϸģʽ�ĺ���ָ��
 */
GAMEMODE ChooseGameMode(int TmpModeCode)
{
    GAMEMODE p = NULL;

    ThisGame = (TIMES*)calloc(1, sizeof(TIMES));
    ThisGame->RoundTimes = 0;
    ThisGame->GameTimes = 0;
    
    p = GameModes[TmpModeCode];
    return p;
}