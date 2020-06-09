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
int GameModeNum;

/**
 * From gameMode.c
 * ������Ϸģʽ����
 */
char* GameModeName[];

/**
 * From gameMode.c
 * ����ģʽ
 */
int ClassGameMode(TIMES*, PLAYER*, PLAYER*);

/**
 * From gameMode.c
 * ������Ѫģʽ
 */
int ThreeBloodGameMode(TIMES*, PLAYER*, PLAYER*);

/**
 * From gameMode.c
 * ��ͽ����ģʽ
 */
int GamblerHellGameMode(TIMES*, PLAYER*, PLAYER*);

/**
 * From gameMode.c
 * ������Ϸģʽ��Ӧ�ĺ���ָ��
 */
typedef const int (*GAMEMODE)(TIMES* ,PLAYER* ,PLAYER*);
extern GAMEMODE GameModes[];


/**
 * From gameMode.c
 * �����Ϸģʽ����
 * 
 * return int ģʽID
 */
int GetGameModeCode(int);
/**
 * From gameMode.c
 * ѡĳһ��Ϸģʽ
 * 
 * int ModeCode ��Ϸģʽ����
 * 
 * return GAMEMODE* ��Ӧ��Ϸģʽ�ĺ���ָ��
 */
GAMEMODE ChooseGameMode(int);