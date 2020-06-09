#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/**
 * From gameModeController.c
 * 负责经典模式的视图管理
 * 
 * 1. PV_P1 && PV_P2 都在0~2之间时，为正常游玩
 * 2. PV_P1 && PV_P2 都是3，表明第一次进入游戏
 * 3. PV_P1 && PV_P2 都是4，表明输入错误
 * 
 * return char IsNext
 */
char ClassModeController(PLAYER*, unsigned char, unsigned char);
/**
 * From gameModecontroller.c
 * 负责三滴血模式的视图管理
 * 
 * 1. PV_P1 && PV_P2 都在0~2之间时，为正常游玩
 * 2. PV_P1 && PV_P2 都是3，表明第一次进入游戏
 * 3. PV_P1 && PV_P2 都是4，表明输入错误
 * 
 * return char IsNext
 */
char ThreeBloodModeController(PLAYER*, PLAYER*, unsigned char, unsigned char);

/**
 * From gameModecontroller.c
 * 负责赌徒地狱模式的视图管理
 * 
 * 1. PV_P1 && PV_P2 都在0~2之间时，为正常游玩
 * 2. PV_P1 && PV_P2 都是3，表明第一次进入游戏
 * 3. PV_P1 && PV_P2 都是4，表明输入错误
 * 
 * return char IsNext
 */
char GamblerHellModeController(PLAYER*, PLAYER*, unsigned char, unsigned char);