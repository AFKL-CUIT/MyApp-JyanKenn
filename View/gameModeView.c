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
 * 定义经典模式视图
 * 
 * char PunchValue_P1 P1出拳值(通常是USER)
 * char PunchValue_P2 P2出拳值
 */
void ViewClassMode(char PunchValue_P1, char PunchValue_P2)
{
    int i = 0;

    if(0 <= PunchValue_P2 && PunchValue_P2 <= 2)
        printf("|  敌方出拳:%-7s|\n", PunchName[PunchValue_P2]);
    else
        printf("|  敌方：等待出拳  |\n");

    printf("|");
    for(i=0; i<18; i++)
        printf("=");
    printf("|\n");

    if(0 <= PunchValue_P1 && PunchValue_P1 <= 2)
        printf("|  我方出拳:%-7s|\n", PunchName[PunchValue_P1]);
    else
        printf("|  我方：等待出拳  |\n");

    printf("|%7d.%-10s|\n", 1, "剪刀");
    printf("|%7d.%-10s|\n", 2, "石头");
    printf("|%7d.%-10s|\n", 3, "布");
}

/**
 * From view.c
 * 定义了三滴血模式的视图
 * 
 * PLAYER* P1 玩家1(通常是USER)
 * char PunchValue_P1 P1出拳值(通常是USER)
 * PLAYER* P2 玩家2
 * char PunchValue_P2 P2出拳值
 */
void ViewThreeBloodMode(PLAYER* P1, char PunchValue_P1, PLAYER* P2, char PunchValue_P2)
{
    int j = 0;

    if(0 <= PunchValue_P2 && PunchValue_P2 <= 2)
        printf("|  敌方出拳:%-7s|\n", PunchName[PunchValue_P2]);
    else
        printf("|  敌方：等待出拳  |\n");

    printf("|=");

    printf("敌:");
    for(j=0; j<P2->HP; j++)
        printf("O");
    for(j=0; j<(3 - P2->HP); j++)
        printf("X");

    for(j=0; j<4; j++)
        printf("=");

    printf("我:");
    for(j=0; j<P1->HP; j++)
        printf("O");
    for(j=0; j<(3 - P1->HP); j++)
        printf("X");

    printf("=|\n");

    if(0 <= PunchValue_P1 && PunchValue_P1 <= 2)
        printf("|  我方出拳:%-7s|\n", PunchName[PunchValue_P1]);
    else
        printf("|  我方：等待出拳  |\n");
    
    printf("|%7d.%-10s|\n", 1, "剪刀");
    printf("|%7d.%-10s|\n", 2, "石头");
    printf("|%7d.%-10s|\n", 3, "布");
}

/**
 * From view.c
 * 定义赌徒地狱模式的视图
 */
void ViewGamblerHellMode(PLAYER* P1, char PunchValue_P1, PLAYER* P2, char PunchValue_P2)
{
    int i = 0;

    if(0 <= PunchValue_P2 && PunchValue_P2 <= 2)
        printf("|  敌方出拳:%-7s|\n", PunchName[PunchValue_P2]);
    else
        printf("|  敌方：等待出拳  |\n");

    printf("|=");
    if(P2->HP > 0)
        printf("敌:%2d", P2->HP);
    else
        printf("敌:%2d", 0);

    for(i=0; i<6; i++)
        printf("=");
    
    if(P1->HP > 0)
        printf("我:%2d", P1->HP);
    else
        printf("我:%2d", 0);
    printf("=|\n");

    if(0 <= PunchValue_P1 && PunchValue_P1 <= 2)
        printf("|  我方出拳:%-7s|\n", PunchName[PunchValue_P1]);
    else
        printf("|  我方：等待出拳  |\n");
    
    printf("|%7d.%-10s|\n", 1, "剪刀");
    printf("|%7d.%-10s|\n", 2, "石头");
    printf("|%7d.%-10s|\n", 3, "布");
}

/**
 * From view.c
 * 定义赢家视图尾部
 */
void ViewWinner(PLAYER* Winner)
{
    if(Winner == USER)
        printf("======我方胜利======\n");
    else if(Winner == NULL)
        printf("======本局平局======\n");
    else
        printf("======敌方胜利======\n");

    printf("==其它.返回主菜单==\n");
    printf("====N.下一局游戏====\n");
}