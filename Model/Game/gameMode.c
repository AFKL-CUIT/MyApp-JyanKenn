#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
这里定义了不同游戏模式的声明和转接
*/

/**
 * From gameMode.c
 * 定义游戏模式数量
 */
int GameModeNum = 3;

/**
 * From gameMode.c
 * 定义游戏模式名字
 */
char* GameModeName[] = {"经典模式", "仅三滴血", "赌徒地狱"};

/**
 * From gameMode.c
 * 经典模式
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
 * 仅三滴血模式
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
 * 赌徒地狱模式
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
 * 定义游戏模式对应的函数指针
 */
typedef const int (*GAMEMODE)(TIMES* ,PLAYER* ,PLAYER*);
GAMEMODE GameModes[] = {ClassGameMode, ThreeBloodGameMode, GamblerHellGameMode};


/**
 * From gameMode.c
 * 获得游戏模式代码
 * 
 * return int 模式ID
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
 * 选某一游戏模式
 * 
 * int ModeCode 游戏模式代码
 * 
 * return GAMEMODE* 对应游戏模式的函数指针
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