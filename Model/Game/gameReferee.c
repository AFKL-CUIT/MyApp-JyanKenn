#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
这里定义了游戏各个细节的流程
*/

/**
 * From gameReferee.c
 * 定义了每局游戏的每回合输赢状态和回合数
 * 
 * PLAYER* WinPlayer 胜利玩家
 * |char| PunchValue_Win 胜利玩家的出拳
 * 
 * PLAYER* LosePlayer 失败玩家
 * |char| PunchValue_Lose 失败玩家出拳
 * 
 * |int| GameTimes 游戏场数
 * |int| RoundTimes 回合数
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

TIMES* ThisGame = NULL;

/**
 * From gameReferee.c
 * 定义当前游戏模式的代号
 */
int ModeCode = 0;

/**
 * From gameReferee.c
 * 定义了不同出拳值的名称
 */
const char* PunchName[3] = {"剪刀", "石头", "布"};

/**
 * From gameReferee.c
 * 记录出拳
 * 
 * PUNCH* TmpPunch 要记录的出拳
 * PLAYER* TmpPlayer 被记录的玩家
 */
void NotePunch(PUNCH* TmpPunch, PLAYER* TmpPlayer)
{
    TmpPunch->LastPunch = TmpPlayer->ThisPunch;
    TmpPlayer->ThisPunch = TmpPunch;
}

/**
 * From gameReferee.c
 * 记录玩家战绩
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
 * 随机数的播种和生成(范围0~2)
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
 * 胜利的玩家流程
 */
void WinPlayer(TIMES* Game, PLAYER* Winner, unsigned char WinnerPV)
{
    Game->WinPlayer = Winner;
    Game->PunchValue_Win = WinnerPV;
}

/**
 * From gameReferee.c
 * 失败玩家流程
 */
void LosePlayer(TIMES* Game, PLAYER* Loser, unsigned char LoserPV)
{
    Game->LosePlayer = Loser;
    Game->PunchValue_Lose = LoserPV;
}

/**
 * From gameReferee.c
 * 定义了胜负判断
 * 
 * TIMES* Games 本局游戏
 * PLAYER* P1 玩家1
 * int Punch1 玩家1本回合出拳
 * PLAYER* P2 玩家2
 * int Punch1 玩家1本回合出拳
 * 
 * return PLAYER* WinP 胜利的玩家，平局返回NULL
 */
PLAYER* JudgeWinAndLose(TIMES* Game, PLAYER* P1, int Punch1, PLAYER* P2, int Punch2)
{
    PLAYER* WinP = NULL;

    PLAYER* WinnerMap[3][3] = {
                                {NULL, P2, P1},
                                {P1, NULL, P2},
                                {P2, P1, NULL}
                              };

    if((0 <= Punch1 && Punch1 <= 2) && (0 <= Punch2 && Punch2 <= 2))
    {
        WinP = WinnerMap[Punch1][Punch2];
        if(WinP == P1)
        {
            WinPlayer(Game, WinP, Punch1);
            LosePlayer(Game, (WinP == P1)?(P2):(P1), Punch2);
        }
        else if(WinP == P2)
        {
            WinPlayer(Game, WinP, Punch2);
            LosePlayer(Game, (WinP == P1)?(P2):(P1), Punch1);
        }
    }
    else
        CatchError();

    return WinP;
}

/**
 * From gameReferee.c
 * 对玩家进行扣血
 */
int DeductHP(PLAYER* Loser, unsigned int HP)
{
    (Loser->HP - HP > 0) ? (Loser->HP -= HP) : (Loser->HP = 0);
    return Loser->HP;
}

/**
 * From gameReferee.c
 * 清空出拳链表
 * 
 * PLAYER* PlayerPunchLink
 */
void UnLinkPunch(PLAYER* PlayerPunch)
{
    PUNCH* Tmp_Del = PlayerPunch->ThisPunch;

    if(Tmp_Del != NULL)
    {
        PUNCH* Tmp_Next = Tmp_Del->LastPunch;

        while(Tmp_Del != NULL)
        {
            Tmp_Next = Tmp_Del->LastPunch;
            free(Tmp_Del);
            Tmp_Del = Tmp_Next;
        }

        PlayerPunch->ThisPunch = NULL;
    }
}

/**
 * From gameReferee.c
 * 当游戏结束时:
 * 1. 清空出拳链表
 * 2. 初始化GameTimes
 * 3. 记录战绩
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