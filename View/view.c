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
void ViewHead()
{
    printf("====================\n");
    printf("======JyanKenn======\n");
    printf("====================\n");
}

/**
 * From view.c
 * 定义尾部视图
 */
void ViewFoot()
{
    printf("====================\n");
    printf("====Made By AFKL====\n");
    printf("====================\n");
}

/**
 * From view.c
 * 定义选择视图
 */
void ViewChoose(int ModeCode, int PageCode)
{
    int i = 0;
    int j = 0;

    for(i=PageCode,j=0;
        i<GameModeNum&&j<2;
        i++,j++)
    {
        if(j != ModeCode-1)
            printf("|%4d.%-13s|\n", j+1, GameModeName[i]);
        else
            printf("|->%2d.%-13s|\n", j+1, GameModeName[i]);
    }

    if(j <= 1)
        printf("|%*s|\n", 18, " ");
    
    printf("|%*s|\n", 18, " ");
    printf("|%4d.%-13s|\n", 3, "数据回顾");
    printf("|%4d.%-13s|\n", 0, "其它模式");
    printf("|%4c.%-13s|\n", 'Y', "按Y确认");
}

/**
 * From view.c
 * 定义数据展示视图
 */
void ViewShowData(GAMEDATA* PlayerData)
{
    printf("|%13s%*s|\n", GameModeName[PlayerData->GameModeId], 5, " ");
    printf("|       胜:%-8d|\n", PlayerData->WTime);
    printf("|       败:%-8d|\n", PlayerData->LTime);
    printf("|       平:%-8d|\n", PlayerData->DTime);
    printf("|%*s|\n", 18, " ");
    printf("|%4c.%-13s|\n", '1', "其它模式");
}

/**
 * From view.c
 * 定义退出页面
 */
void ViewExit()
{
    printf("|%*s|\n", 18, " ");
    printf("|%*s|\n", 18, " ");
    printf("|     Good Bye     |\n");
    printf("|%*s|\n", 18, " ");
    printf("|%*s|\n", 18, " ");
    printf("|%*s|\n", 18, " ");
}

/**
 * From view.c
 * 定义警告尾部
 */
void ViewPrompt(char* PromptStr)
{
    printf("====================\n");
    printf("======%s======\n", PromptStr);
    printf("====================\n");
}

/**
 * From view.c
 * 定义错误页面主体
 */
void ViewErrorBody()
{
    printf("|or    Error     Er|\n");
    printf("|    Error   Error |\n");
    printf("|Error   Error   Er|\n");
    printf("|ror   Error   Erro|\n");
    printf("|%*s|\n", 18, " ");
    printf("|%s|\n", "flag{Err0r_1s_B4d}");
}

/**
 * From view.c
 * 定义错误页面尾部
 */
void ViewErrorFoot()
{
    printf("====================\n");
    printf("=程序错误，回车退出=\n");
    printf("====================\n");
}
