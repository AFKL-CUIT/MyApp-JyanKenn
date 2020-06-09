#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
这里定义了玩家的各个属性及行为
这里AI也属于玩家
*/

/**
 * From player.c
 * 定义玩家的出拳记录
 * 
 * |char| PunchValue 出拳的值
 * PUNCH* LastPunch 指向上一次出拳的结构体
 */
typedef struct punch
{
    unsigned char PunchValue; 
    struct punch* LastPunch;
}PUNCH;

/**
 * From player.c
 * 定义玩家的游戏记录
 * 
 * |int| GameModeId 游戏模式ID
 * |int| WTime 胜利次数
 * |int| LTime 失败次数
 * |int| DTime 平局次数
 * GAMADATA* NextGameMode 指向另一个游戏模式的结构体
 */
typedef struct GameData
{
    unsigned int GameModeId;
    unsigned int WTime;
    unsigned int LTime;
    unsigned int DTime;
    struct GameData* NextGameMode;
}GAMEDATA;

/**
 * From player.c
 * 定义玩家的各项属性值
 * 
 * |int| HP 玩家生命值
 * PUNCH* ThisPunch 指向本次玩家出拳的结构体
 * GAMEDATA* PlayerGameData 指向玩家的游戏状态
 */
typedef struct player
{
    int HP;
    PUNCH* ThisPunch;
    GAMEDATA* PlayerGameData;
}PLAYER;

/**
 * From player.c
 * 定义了玩家
 */
PLAYER* USER = NULL;

/**
 * From player.c
 * 定义了AI
 */
PLAYER* AI = NULL;

/**
 * From player.c
 * 初始化玩家
 */
void InitPlayer()
{
    USER = (PLAYER*)calloc(1, sizeof(PLAYER));
    USER->PlayerGameData = (GAMEDATA*)calloc(1, sizeof(GAMEDATA));
    USER->ThisPunch = NULL;

    AI = (PLAYER*)calloc(1, sizeof(PLAYER));
    AI->PlayerGameData = NULL;
    AI->ThisPunch = NULL;
}

/**
 * From player.c
 * 初始化角色血量
 * 
 * PLAYER* P1 角色指针
 * int P1_HP P1的HP
 * PLAYER* P2 角色指针
 * int P2_HP P2的HP
 */
void InitPlayerHP(PLAYER* P1, int P1_HP, PLAYER* P2, int P2_HP)
{
    P1->HP = P1_HP;
    P2->HP = P2_HP;
}

/**
 * From player.c
 * 角色出拳
 * 
 * |char| PunchValue 出拳值
 * 
 * return PUNCH* 指向本次出拳的指针
 */
PUNCH* PlayerPunch(const unsigned char PunchValue)
{
    PUNCH* TmpPunch = (PUNCH*)malloc(sizeof(PUNCH));

    TmpPunch->PunchValue = PunchValue;
    TmpPunch->LastPunch = NULL;

    return TmpPunch;
}

/**
 * From player.c
 * AI出拳 - 随机模式
 * 
 * return |char| PunchValue 出拳值
 */
unsigned char AIGetPunch_R()
{
    unsigned char PunchValue = 0;
    PunchValue = (char)RandNum();
    return PunchValue;
}

/**
 * From player.c
 * AI出拳 - 防御模式
 * 
 * return |char| PunchValue 出拳值
 */
unsigned char AIGetPunch_D()
{
    unsigned char PunchValue = 0;

    int PunchMap[3] = {0, 0, 0};
    PUNCH* Tmp = USER->ThisPunch;

    for(; Tmp!=NULL; Tmp=Tmp->LastPunch)
        PunchMap[Tmp->PunchValue]++;

    if(PunchMap[0] < PunchMap[1])
    {
        if(PunchMap[1] < PunchMap[2])
            PunchValue = 0;
        else
            PunchValue = 2;
    }else
    {
        if(PunchMap[0] < PunchMap[2])
            PunchValue = 0;
        else
            PunchValue = 1;
    }
    
    return PunchValue;
}

/**
 * From player.c
 * AI出拳 - 攻击模式
 * 
 * return |char| PunchValue 出拳值
 */
unsigned char AIGetPunch_A()
{
    unsigned char PunchValue = 0;
    unsigned char USERLastPunch = 0;

    if(USER->ThisPunch != NULL)
        USERLastPunch = USER->ThisPunch->LastPunch->PunchValue;

    if(USERLastPunch != 2)
        PunchValue = USERLastPunch + 1;
    else
        PunchValue = 0;
    
    return PunchValue;
}

/**
 * From player.c
 * AI出拳 - 放水模式
 * 
 * return |char| PunchValue
 */
unsigned char AIGetPunch_F()
{
    unsigned char PunchValue = 0;

    int PunchMap[3] = {0, 0, 0};
    PUNCH* Tmp = USER->ThisPunch;

    for(; Tmp!=NULL; Tmp=Tmp->LastPunch)
        PunchMap[Tmp->PunchValue]++;

    if(PunchMap[0] < PunchMap[1])
    {
        if(PunchMap[1] < PunchMap[2])
            PunchValue = 1;
        else
            PunchValue = 0;
    }else
    {
        if(PunchMap[0] < PunchMap[2])
            PunchValue = 1;
        else
            PunchValue = 2;
    }

    return PunchValue;
}

/**
 * From player.c
 * AI策略
 * 
 * int Times 依据TIMES的(GameTimes/RoundTimes)进行决策
 * 
 * retrun |char| PunchValue
 */
unsigned char strategy_AI(int Times)
{
    unsigned char PunchValue = 0;

    PunchValue = AIGetPunch_R();

    if((Times % 3) == 0 || USER->HP > AI->HP)
        PunchValue = AIGetPunch_D();
    else if(USER->HP == 1 && AI->HP > USER->HP)
        PunchValue = AIGetPunch_F();
    else if(USER->HP + 1 < AI->HP)
        PunchValue = AIGetPunch_A();

    return PunchValue;
}


/**
 * From player.c
 * 释放内存
 * 
 * PLAYER* Player 要释放的用户
 */
void UnLinkPlayer(PLAYER* Player)
{
    GAMEDATA* FreeTmp_Next = NULL;
    GAMEDATA* FreeTmp_Del = Player->PlayerGameData;

    while(FreeTmp_Del)
    {
        FreeTmp_Next = FreeTmp_Del->NextGameMode;
        free(FreeTmp_Del);
        FreeTmp_Del = FreeTmp_Next;
    }
    
    Player->PlayerGameData = NULL;
    free(Player);
    Player = NULL;
}