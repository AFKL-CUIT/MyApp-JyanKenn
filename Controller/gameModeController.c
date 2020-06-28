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
char ClassModeController(PLAYER* Winner, unsigned char PV_P1, unsigned char PV_P2)
{
    char IsNext = 0;

    Clear();
    ViewGameHead(GameModeName[ModeCode]);
    if(PV_P1 == 3 && PV_P2 == 3)
    {
        ViewClassMode(3, 3);
        ViewFoot();
    }
    else if(PV_P1 == 4 && PV_P2 == 4)
    {
        ViewClassMode(3, 3);
        ViewPrompt("输入有误");
    }
    else
    {
        ViewClassMode(PV_P1, PV_P2);
        ViewWinner(Winner);

        IsNext = (char)getch();
    }

    return IsNext;
}

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
char ThreeBloodModeController(PLAYER* Winner, PLAYER* Loser, unsigned char PV_P1, unsigned char PV_P2)
{
    char IsNext = 0;

    Clear();
    ViewGameHead(GameModeName[ModeCode]);
    if(PV_P1 == 3 && PV_P2 == 3)
    {
        ViewThreeBloodMode(USER, 3, AI, 3);
        ViewFoot();
    }
    else if(PV_P1 == 4 && PV_P2 == 4)
    {
        ViewThreeBloodMode(USER, 3, AI, 3);
        ViewPrompt("输入有误");
    }
    else
    {
        ViewThreeBloodMode(USER, PV_P1, AI, PV_P2);
        if(Loser->HP == 0)
        {
            ViewWinner(Winner);
            IsNext = (char)getch();
        }
        else
            ViewFoot();
    }

    return IsNext;
}

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
char GamblerHellModeController(PLAYER* Winner, PLAYER* Loser, unsigned char PV_P1, unsigned char PV_P2)
{
    char IsNext = 0;

    Clear();
    ViewGameHead(GameModeName[ModeCode]);
    if(PV_P1 == 3 && PV_P2 == 3)
    {
        ViewGamblerHellMode(USER, 3, AI, 3);
        ViewPrompt("ID为倍率");
    }
    else if(PV_P1 == 4 && PV_P2 == 4)
    {
        ViewGamblerHellMode(USER, 3, AI, 3);
        ViewPrompt("输入有误");
    }
    else
    {
        ViewGamblerHellMode(USER, PV_P1, AI, PV_P2);
        if(Loser->HP <= 0)
        {
            ViewWinner(Winner);
            IsNext = (char)getch();
        }
        else
            ViewFoot();
    }

    return IsNext;
}