#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/**
 * From gameModeController.c
 * ���𾭵�ģʽ����ͼ����
 * 
 * 1. PV_P1 && PV_P2 ����0~2֮��ʱ��Ϊ��������
 * 2. PV_P1 && PV_P2 ����3��������һ�ν�����Ϸ
 * 3. PV_P1 && PV_P2 ����4�������������
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
        ViewPrompt("��������");
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
 * ��������Ѫģʽ����ͼ����
 * 
 * 1. PV_P1 && PV_P2 ����0~2֮��ʱ��Ϊ��������
 * 2. PV_P1 && PV_P2 ����3��������һ�ν�����Ϸ
 * 3. PV_P1 && PV_P2 ����4�������������
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
        ViewPrompt("��������");
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
 * �����ͽ����ģʽ����ͼ����
 * 
 * 1. PV_P1 && PV_P2 ����0~2֮��ʱ��Ϊ��������
 * 2. PV_P1 && PV_P2 ����3��������һ�ν�����Ϸ
 * 3. PV_P1 && PV_P2 ����4�������������
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
        ViewPrompt("IDΪ����");
    }
    else if(PV_P1 == 4 && PV_P2 == 4)
    {
        ViewGamblerHellMode(USER, 3, AI, 3);
        ViewPrompt("��������");
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