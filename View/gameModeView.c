#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

void ViewGameHead(char* ModeName)
{
    printf("====================\n");
    printf("=%*s%-13s=\n", 5, " ", ModeName);
    printf("====================\n");
}

/**
 * From view.c
 * ���徭��ģʽ��ͼ
 * 
 * char PunchValue_P1 P1��ȭֵ(ͨ����USER)
 * char PunchValue_P2 P2��ȭֵ
 */
void ViewClassMode(char PunchValue_P1, char PunchValue_P2)
{
    int i = 0;

    if(0 <= PunchValue_P2 && PunchValue_P2 <= 2)
        printf("|  �з���ȭ:%-7s|\n", PunchName[PunchValue_P2]);
    else
        printf("|  �з����ȴ���ȭ  |\n");

    printf("|");
    for(i=0; i<18; i++)
        printf("=");
    printf("|\n");

    if(0 <= PunchValue_P1 && PunchValue_P1 <= 2)
        printf("|  �ҷ���ȭ:%-7s|\n", PunchName[PunchValue_P1]);
    else
        printf("|  �ҷ����ȴ���ȭ  |\n");

    printf("|%7d.%-10s|\n", 1, "����");
    printf("|%7d.%-10s|\n", 2, "ʯͷ");
    printf("|%7d.%-10s|\n", 3, "��");
}

/**
 * From view.c
 * ����������Ѫģʽ����ͼ
 * 
 * PLAYER* P1 ���1(ͨ����USER)
 * char PunchValue_P1 P1��ȭֵ(ͨ����USER)
 * PLAYER* P2 ���2
 * char PunchValue_P2 P2��ȭֵ
 */
void ViewThreeBloodMode(PLAYER* P1, char PunchValue_P1, PLAYER* P2, char PunchValue_P2)
{
    int j = 0;

    if(0 <= PunchValue_P2 && PunchValue_P2 <= 2)
        printf("|  �з���ȭ:%-7s|\n", PunchName[PunchValue_P2]);
    else
        printf("|  �з����ȴ���ȭ  |\n");

    printf("|=");

    printf("��:");
    for(j=0; j<P2->HP; j++)
        printf("O");
    for(j=0; j<(3 - P2->HP); j++)
        printf("X");

    for(j=0; j<4; j++)
        printf("=");

    printf("��:");
    for(j=0; j<P1->HP; j++)
        printf("O");
    for(j=0; j<(3 - P1->HP); j++)
        printf("X");

    printf("=|\n");

    if(0 <= PunchValue_P1 && PunchValue_P1 <= 2)
        printf("|  �ҷ���ȭ:%-7s|\n", PunchName[PunchValue_P1]);
    else
        printf("|  �ҷ����ȴ���ȭ  |\n");
    
    printf("|%7d.%-10s|\n", 1, "����");
    printf("|%7d.%-10s|\n", 2, "ʯͷ");
    printf("|%7d.%-10s|\n", 3, "��");
}

/**
 * From view.c
 * �����ͽ����ģʽ����ͼ
 */
void ViewGamblerHellMode(PLAYER* P1, char PunchValue_P1, PLAYER* P2, char PunchValue_P2)
{
    int i = 0;

    if(0 <= PunchValue_P2 && PunchValue_P2 <= 2)
        printf("|  �з���ȭ:%-7s|\n", PunchName[PunchValue_P2]);
    else
        printf("|  �з����ȴ���ȭ  |\n");

    printf("|=");
    if(P2->HP > 0)
        printf("��:%2d", P2->HP);
    else
        printf("��:%2d", 0);

    for(i=0; i<6; i++)
        printf("=");
    
    if(P1->HP > 0)
        printf("��:%2d", P1->HP);
    else
        printf("��:%2d", 0);
    printf("=|\n");

    if(0 <= PunchValue_P1 && PunchValue_P1 <= 2)
        printf("|  �ҷ���ȭ:%-7s|\n", PunchName[PunchValue_P1]);
    else
        printf("|  �ҷ����ȴ���ȭ  |\n");
    
    printf("|%7d.%-10s|\n", 1, "����");
    printf("|%7d.%-10s|\n", 2, "ʯͷ");
    printf("|%7d.%-10s|\n", 3, "��");
}

/**
 * From view.c
 * ����Ӯ����ͼβ��
 */
void ViewWinner(PLAYER* Winner)
{
    if(Winner == USER)
        printf("======�ҷ�ʤ��======\n");
    else if(Winner == NULL)
        printf("======����ƽ��======\n");
    else
        printf("======�з�ʤ��======\n");

    printf("==����.�������˵�==\n");
    printf("====N.��һ����Ϸ====\n");
}