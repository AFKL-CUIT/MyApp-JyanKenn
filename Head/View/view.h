#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
这里定义了游戏的视图
*/

/**
 * From view.c
 * 定义头部视图
 */
void ViewHead();

/**
 * From view.c
 * 定义尾部视图
 */
void ViewFoot();

/**
 * From view.c
 * 定义选择视图
 */
void ViewChoose(int ModeCode, int PageCode);

/**
 * From view.c
 * 定义数据展示视图
 */
void ViewShowData(GAMEDATA* PlayerData);

/**
 * From view.c
 * 定义退出页面
 */
void ViewExit();

/**
 * From view.c
 * 定义警告尾部
 */
void ViewPrompt(char* PromptStr);

/**
 * From view.c
 * 定义错误页面主体
 */
void ViewErrorBody();

/**
 * From view.c
 * 定义错误页面尾部
 */
void ViewErrorFoot();