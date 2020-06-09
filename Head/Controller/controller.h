#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
控制器，负责流程控制
*/

void test();

/**
 * From controller.c
 * 清屏
 */
void Clear();

/**
 * From controller.c
 * 程序初始化
 */
void InitExe();

/**
 * From controller.c
 * 游戏初始化
 */
void InitGame();

/**
 * From controller.c
 * 小错误
 */
void LittleError();

/**
 * From controller.c
 * 负责游戏数据的转接
 */
void IntoGame(int TmpModeCode);

/**
 * From controller.c
 * 退出游戏
 */
void ExitGame();

/**
 * From controller.c
 * 捕捉错误
 */
void CatchError();