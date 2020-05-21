#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
���ﶨ������Ϸ����ͼ
*/

/**
 * From view.c
 * ����ͷ����ͼ
 */
void ViewHead()
{
    printf("====================\n");
    printf("======JyanKenn======\n");
    printf("====================\n");
}

/**
 * From view.c
 * ����β����ͼ
 */
void ViewFoot()
{
    printf("====================\n");
    printf("====Made By AFKL====\n");
    printf("====================\n");
}

/**
 * From view.c
 * ����ѡ����ͼ
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
    printf("|%4d.%-13s|\n", 3, "���ݻع�");
    printf("|%4d.%-13s|\n", 0, "����ģʽ");
    printf("|%4c.%-13s|\n", 'Y', "��Yȷ��");
}

/**
 * From view.c
 * ��������չʾ��ͼ
 */
void ViewShowData(GAMEDATA* PlayerData)
{
    printf("|%13s%*s|\n", GameModeName[PlayerData->GameModeId], 5, " ");
    printf("|       ʤ:%-8d|\n", PlayerData->WTime);
    printf("|       ��:%-8d|\n", PlayerData->LTime);
    printf("|       ƽ:%-8d|\n", PlayerData->DTime);
    printf("|%*s|\n", 18, " ");
    printf("|%4c.%-13s|\n", '1', "����ģʽ");
}

/**
 * From view.c
 * �����˳�ҳ��
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
 * ���徯��β��
 */
void ViewPrompt(char* PromptStr)
{
    printf("====================\n");
    printf("======%s======\n", PromptStr);
    printf("====================\n");
}

/**
 * From view.c
 * �������ҳ������
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
 * �������ҳ��β��
 */
void ViewErrorFoot()
{
    printf("====================\n");
    printf("=������󣬻س��˳�=\n");
    printf("====================\n");
}
