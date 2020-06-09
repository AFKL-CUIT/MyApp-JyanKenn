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
char ClassModeController(PLAYER*, unsigned char, unsigned char);
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
char ThreeBloodModeController(PLAYER*, PLAYER*, unsigned char, unsigned char);

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
char GamblerHellModeController(PLAYER*, PLAYER*, unsigned char, unsigned char);