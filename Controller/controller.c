#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
控制器，负责流程控制
*/

void test()
{
    system("pause");
}

/**
 * From controller.c
 * 清屏
 */
void Clear()
{
    system("cls");
}

/**
 * From controller.c
 * 程序初始化
 */
void InitExe()
{
    InitPlayer();
    InitSave();
}

/**
 * From controller.c
 * 游戏初始化
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
        IsError ? ViewPrompt("选择有误") : ViewFoot();

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
 * 小错误
 */
void LittleError()
{
    Clear();
    ViewHead();
    ViewErrorBody();
    ViewPrompt("选择有误");
    sleep(1);
}

/**
 * From controller.c
 * 负责游戏数据的转接
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
 * 展示玩家数据
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
 * 退出游戏
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
 * 捕捉错误
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