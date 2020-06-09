#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

void ViewGameHead(char*);

/**
 * From view.c
 * 定义经典模式视图
 * 
 * char PunchValue_P1 P1出拳值(通常是USER)
 * char PunchValue_P2 P2出拳值
 */
void ViewClassMode(char, char);

/**
 * From view.c
 * 定义了三滴血模式的视图
 * 
 * PLAYER* P1 玩家1(通常是USER)
 * char PunchValue_P1 P1出拳值(通常是USER)
 * PLAYER* P2 玩家2
 * char PunchValue_P2 P2出拳值
 */
void ViewThreeBloodMode(PLAYER*, char, PLAYER*, char);

/**
 * From view.c
 * 定义赌徒地狱模式的视图
 */
void ViewGamblerHellMode(PLAYER*, char, PLAYER*, char);

/**
 * From view.c
 * 定义赢家视图尾部
 */
void ViewWinner(PLAYER*);