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
typedef struct punch PUNCH;

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
typedef struct GameData GAMEDATA;

/**
 * From player.c
 * ������ҵĸ�������ֵ
 * 
 * |int| HP �������ֵ
 * PUNCH* ThisPunch ָ�򱾴���ҳ�ȭ�Ľṹ��
 * GAMEDATA* PlayerGameData ָ����ҵ���Ϸ״̬
 */
typedef struct player PLAYER;

/**
 * From player.c
 * ���������
 */
extern PLAYER* USER;

/**
 * From player.c
 * ������AI
 */
extern PLAYER* AI;

/**
 * From player.c
 * ��ʼ�����
 */
void InitPlayer();

/**
 * From player.c
 * ��ʼ����ɫѪ��
 * 
 * PLAYER* P1 ��ɫָ��
 * int P1_HP P1��HP
 * PLAYER* P2 ��ɫָ��
 * int P2_HP P2��HP
 */
void InitPlayerHP(PLAYER*, int, PLAYER*, int);

/**
 * From player.c
 * ��ɫ��ȭ
 * 
 * |char| PunchValue ��ȭֵ
 * 
 * return PUNCH* ָ�򱾴γ�ȭ��ָ��
 */
PUNCH* PlayerPunch(const unsigned char);

/**
 * From player.c
 * AI��ȭ - ���ģʽ
 * 
 * return |char| PunchValue ��ȭֵ
 */
unsigned char AIGetPunch_R();

/**
 * From player.c
 * AI��ȭ - ����ģʽ
 * 
 * return |char| PunchValue ��ȭֵ
 */
unsigned char AIGetPunch_D();

/**
 * From player.c
 * AI��ȭ - ����ģʽ
 * 
 * return |char| PunchValue ��ȭֵ
 */
unsigned char AIGetPunch_A();

/**
 * From player.c
 * AI��ȭ - ��ˮģʽ
 * 
 * return |char| PunchValue
 */
unsigned char AIGetPunch_F();

/**
 * From player.c
 * AI����
 * 
 * int Times ����TIMES��(GameTimes/RoundTimes)���о���
 * 
 * retrun |char| PunchValue
 */
unsigned char strategy_AI(int);

/**
 * From player.c
 * �ͷ��ڴ�
 * 
 * PLAYER* Player Ҫ�ͷŵ��û�
 */
void UnLinkPlayer(PLAYER*);