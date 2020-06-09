#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
���������������̿���
*/

void test()
{
    system("pause");
}

/**
 * From controller.c
 * ����
 */
void Clear()
{
    system("cls");
}

/**
 * From controller.c
 * �����ʼ��
 */
void InitExe()
{
    InitPlayer();
    InitSave();
}

/**
 * From controller.c
 * ��Ϸ��ʼ��
 */
void InitGame()
{
    int IsError = 0;
    int TmpCode = 1;
    int TmpModeCode = 1;
    int PageCode = 0;

    while(TmpCode >= 0)
    {
        Clear();
        ViewHead();
        ViewChoose(TmpCode, PageCode);
        IsError ? ViewPrompt("ѡ������") : ViewFoot();

        IsError = False;
        TmpCode = GetGameModeCode(getch());

        if(TmpCode > GameModeNum)
        {
            if(TmpCode == 121 && TmpModeCode+PageCode-1 < GameModeNum)
            {
                IntoGame(TmpModeCode+PageCode-1);
                TmpCode = 1;
                TmpModeCode = TmpCode;
            }
            else
                IsError = True;
        }
        else
        {
            if(TmpCode == 3)
            {
                ShowData();
                TmpCode = 1;
            }
            else if(TmpCode == 0)
            {
                if(PageCode+2 < GameModeNum)
                {
                    PageCode += 2;
                    ModeCode = 1;
                }
                else
                    PageCode = 0;

                TmpCode = 1;
            }
            else
                TmpModeCode = TmpCode;
        }
    }
}

/**
 * From controller.c
 * С����
 */
void LittleError()
{
    Clear();
    ViewHead();
    ViewErrorBody();
    ViewPrompt("ѡ������");
    sleep(1);
}

/**
 * From controller.c
 * ������Ϸ���ݵ�ת��
 */
void IntoGame(int TmpModeCode)
{
    ModeCode = TmpModeCode;

    int IsError = 0;
    GAMEMODE GAME = NULL;

    GAME = ChooseGameMode(ModeCode);

    Clear();
    
    IsError = GAME(ThisGame, USER, AI);

    if(IsError)
        CatchError();

    GameOver();
}

/**
 * From controller.c
 * չʾ�������
 */
void ShowData()
{
    int IsNext = 49;
    GAMEDATA* PlayerData = USER->PlayerGameData;

    while(IsNext == 49)
    {
        Clear();
        ViewHead();
        ViewShowData(PlayerData);
        ViewFoot();

        IsNext = getch();
        if(IsNext == 49)
        {
            PlayerData = PlayerData->NextGameMode;

            if(PlayerData == NULL)
                PlayerData = USER->PlayerGameData;
        }
    }
}

/**
 * From controller.c
 * �˳���Ϸ
 */
void ExitGame()
{
    UnLinkPlayer(USER);
    UnLinkPlayer(AI);
    CloseFile();

    Clear();
    ViewHead();
    ViewExit();
    ViewFoot();
    sleep(3);
}

/**
 * From controller.c
 * ��׽����
 */
void CatchError()
{
    UnLinkPlayer(USER);
    UnLinkPlayer(AI);
    CloseFile();

    Clear();
    ViewHead();
    ViewErrorBody();
    ViewErrorFoot();
    getch();
    exit(0);
}