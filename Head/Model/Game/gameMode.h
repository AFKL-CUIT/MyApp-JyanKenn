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
int GameModeNum;

/**
 * From gameMode.c
 * 定义游戏模式名字
 */
char* GameModeName[];

/**
 * From gameMode.c
 * 经典模式
 */
int ClassGameMode(TIMES*, PLAYER*, PLAYER*);

/**
 * From gameMode.c
 * 仅三滴血模式
 */
int ThreeBloodGameMode(TIMES*, PLAYER*, PLAYER*);

/**
 * From gameMode.c
 * 赌徒地狱模式
 */
int GamblerHellGameMode(TIMES*, PLAYER*, PLAYER*);

/**
 * From gameMode.c
 * 定义游戏模式对应的函数指针
 */
typedef const int (*GAMEMODE)(TIMES* ,PLAYER* ,PLAYER*);
extern GAMEMODE GameModes[];


/**
 * From gameMode.c
 * 获得游戏模式代码
 * 
 * return int 模式ID
 */
int GetGameModeCode(int);
/**
 * From gameMode.c
 * 选某一游戏模式
 * 
 * int ModeCode 游戏模式代码
 * 
 * return GAMEMODE* 对应游戏模式的函数指针
 */
GAMEMODE ChooseGameMode(int);