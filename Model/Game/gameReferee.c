#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
���ﶨ������Ϸ����ϸ�ڵ�����
*/

/**
 * From gameReferee.c
 * ������ÿ����Ϸ��ÿ�غ���Ӯ״̬�ͻغ���
 * 
 * PLAYER* WinPlayer ʤ�����
 * |char| PunchValue_Win ʤ����ҵĳ�ȭ
 * 
 * PLAYER* LosePlayer ʧ�����
 * |char| PunchValue_Lose ʧ����ҳ�ȭ
 * 
 * |int| GameTimes ��Ϸ����
 * |int| RoundTimes �غ���
 */
typedef struct Times
{
    PLAYER* WinPlayer;
    unsigned char PunchValue_Win;

    PLAYER* LosePlayer;
    unsigned char PunchValue_Lose;

    unsigned int GameTimes;
    unsigned int RoundTimes;
}TIMES;

extern TIMES* ThisGame = NULL;

/**
 * From gameReferee.c
 * ���嵱ǰ��Ϸģʽ�Ĵ���
 */
extern int ModeCode = 0;

/**
 * From gameReferee.c
 * �����˲�ͬ��ȭֵ������
 */
const char* PunchName[3] = {"����", "ʯͷ", "��"};

/**
 * From gameReferee.c
 * ��¼��ȭ
 * 
 * PUNCH* TmpPunch Ҫ��¼�ĳ�ȭ
 * PLAYER* TmpPlayer ����¼�����
 */
void NotePunch(PUNCH* TmpPunch, PLAYER* TmpPlayer)
{
    TmpPunch->LastPunch = TmpPlayer->ThisPunch;
    TmpPlayer->ThisPunch = TmpPunch;
}

/**
 * From gameReferee.c
 * ��¼���ս��
 */
void NoteGameData(PLAYER* Winner)
{
    GAMEDATA* Tmp = NULL;

    for(Tmp=USER->PlayerGameData; Tmp!=NULL; Tmp=Tmp->NextGameMode)
    {
        if(Tmp->GameModeId == ModeCode)
            break;
    }

    if(Winner == USER)
        Tmp->WTime++;
    else if(Winner == NULL)
        Tmp->DTime++;
    else
        Tmp->LTime++;
}

/**
 * From gameReferee.c
 * ������Ĳ��ֺ�����(��Χ0~2)
 * 
 * return int RandValue;
 */
int RandNum()
{
    int RandValue = 0;
    RandValue = rand() % 3;

    srand((unsigned int)time(NULL));

    return RandValue;
}

/**
 * From gameReferee.c
 * ʤ�����������
 */
void WinPlayer(TIMES* Game, PLAYER* Winner, unsigned char WinnerPV)
{
    Game->WinPlayer = Winner;
    Game->PunchValue_Win = WinnerPV;
}

/**
 * From gameReferee.c
 * ʧ���������
 */
void LosePlayer(TIMES* Game, PLAYER* Loser, unsigned char LoserPV)
{
    Loser->HP--;
    Game->LosePlayer = Loser;
    Game->PunchValue_Lose = LoserPV;
}

/**
 * From gameReferee.c
 * ������ʤ���ж�
 * 
 * TIMES* Games ������Ϸ
 * PLAYER* P1 ���1
 * int Punch1 ���1���غϳ�ȭ
 * PLAYER* P2 ���2
 * int Punch1 ���1���غϳ�ȭ
 * 
 * return PLAYER* WinP ʤ������ң�ƽ�ַ���NULL
 */
PLAYER* JudgeWinAndLose(TIMES* Game, PLAYER* P1, int Punch1, PLAYER* P2, int Punch2)
{
    PLAYER* WinP = NULL;
    if(Punch1 < Punch2)
    {
        if(Punch2==2 && Punch1==0)
        {
            WinPlayer(Game, P1, Punch1);
            LosePlayer(Game, P2, Punch2);
            WinP = P1;
        }
        else
        {
            WinPlayer(Game, P2, Punch2);
            LosePlayer(Game, P1, Punch1);
            WinP = P2;
        }
    }
    else if(Punch2 < Punch1)
    {
        if(Punch1==2 && Punch2==0)
        {
            WinPlayer(Game, P2, Punch2);
            LosePlayer(Game, P1, Punch1);
            WinP = P2;
        }
        else
        {
            WinPlayer(Game, P1, Punch1);
            LosePlayer(Game, P2, Punch2);
            WinP = P1;
        }
    }
    else
    {
        Game->WinPlayer = NULL;
        Game->LosePlayer = NULL;
    }
    return WinP;
}

/**
 * From gameReferee.c
 * ��ճ�ȭ����
 * 
 * PLAYER* PlayerPunchLink
 */
void UnLinkPunch(PLAYER* PlayerPunch)
{
    PUNCH* Tmp_Del = PlayerPunch->ThisPunch;

    if(Tmp_Del == NULL)
        return 0;

    PUNCH* Tmp_Next = Tmp_Del->LastPunch;

    while(Tmp_Del != NULL)
    {
        Tmp_Next = Tmp_Del->LastPunch;
        free(Tmp_Del);
        Tmp_Del = Tmp_Next;
    }

    PlayerPunch->ThisPunch = NULL;
}

/**
 * From gameReferee.c
 * ����Ϸ����ʱ:
 * 1. ��ճ�ȭ����
 * 2. ��ʼ��GameTimes
 * 3. ��¼ս��
 */
void GameOver()
{
    UnLinkPunch(USER);
    UnLinkPunch(AI);

    ThisGame->PunchValue_Win = ThisGame->PunchValue_Lose = 3;
    ThisGame->WinPlayer = ThisGame->LosePlayer = NULL;
    ThisGame->RoundTimes = 0;

    SaveGameData();
}