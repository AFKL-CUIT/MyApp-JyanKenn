#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

void ViewGameHead(char*);

/**
 * From view.c
 * ���徭��ģʽ��ͼ
 * 
 * char PunchValue_P1 P1��ȭֵ(ͨ����USER)
 * char PunchValue_P2 P2��ȭֵ
 */
void ViewClassMode(char, char);

/**
 * From view.c
 * ����������Ѫģʽ����ͼ
 * 
 * PLAYER* P1 ���1(ͨ����USER)
 * char PunchValue_P1 P1��ȭֵ(ͨ����USER)
 * PLAYER* P2 ���2
 * char PunchValue_P2 P2��ȭֵ
 */
void ViewThreeBloodMode(PLAYER*, char, PLAYER*, char);

/**
 * From view.c
 * �����ͽ����ģʽ����ͼ
 */
void ViewGamblerHellMode(PLAYER*, char, PLAYER*, char);

/**
 * From view.c
 * ����Ӯ����ͼβ��
 */
void ViewWinner(PLAYER*);