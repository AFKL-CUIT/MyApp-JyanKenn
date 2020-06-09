#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
���ﶨ������ҵĸ������Լ���Ϊ
����AIҲ�������
*/

/**
 * From player.c
 * ������ҵĳ�ȭ��¼
 * 
 * |char| PunchValue ��ȭ��ֵ
 * PUNCH* LastPunch ָ����һ�γ�ȭ�Ľṹ��
 */
typedef struct punch
{
    unsigned char PunchValue; 
    struct punch* LastPunch;
}PUNCH;

/**
 * From player.c
 * ������ҵ���Ϸ��¼
 * 
 * |int| GameModeId ��ϷģʽID
 * |int| WTime ʤ������
 * |int| LTime ʧ�ܴ���
 * |int| DTime ƽ�ִ���
 * GAMADATA* NextGameMode ָ����һ����Ϸģʽ�Ľṹ��
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
 * ������ҵĸ�������ֵ
 * 
 * |int| HP �������ֵ
 * PUNCH* ThisPunch ָ�򱾴���ҳ�ȭ�Ľṹ��
 * GAMEDATA* PlayerGameData ָ����ҵ���Ϸ״̬
 */
typedef struct player
{
    int HP;
    PUNCH* ThisPunch;
    GAMEDATA* PlayerGameData;
}PLAYER;

/**
 * From player.c
 * ���������
 */
PLAYER* USER = NULL;

/**
 * From player.c
 * ������AI
 */
PLAYER* AI = NULL;

/**
 * From player.c
 * ��ʼ�����
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
 * ��ʼ����ɫѪ��
 * 
 * PLAYER* P1 ��ɫָ��
 * int P1_HP P1��HP
 * PLAYER* P2 ��ɫָ��
 * int P2_HP P2��HP
 */
void InitPlayerHP(PLAYER* P1, int P1_HP, PLAYER* P2, int P2_HP)
{
    P1->HP = P1_HP;
    P2->HP = P2_HP;
}

/**
 * From player.c
 * ��ɫ��ȭ
 * 
 * |char| PunchValue ��ȭֵ
 * 
 * return PUNCH* ָ�򱾴γ�ȭ��ָ��
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
 * AI��ȭ - ���ģʽ
 * 
 * return |char| PunchValue ��ȭֵ
 */
unsigned char AIGetPunch_R()
{
    unsigned char PunchValue = 0;
    PunchValue = (char)RandNum();
    return PunchValue;
}

/**
 * From player.c
 * AI��ȭ - ����ģʽ
 * 
 * return |char| PunchValue ��ȭֵ
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
 * AI��ȭ - ����ģʽ
 * 
 * return |char| PunchValue ��ȭֵ
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
 * AI��ȭ - ��ˮģʽ
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
 * AI����
 * 
 * int Times ����TIMES��(GameTimes/RoundTimes)���о���
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
 * �ͷ��ڴ�
 * 
 * PLAYER* Player Ҫ�ͷŵ��û�
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