#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
定义文件操作
*/

/**
 * From fileIO.c
 * 定义存档的文件指针
 */
FILE* fp = NULL;

/**
 * From fileIO.c
 * 打开文件
 */
void OpenSaveFile()
{
    fp = fopen("PlayerSave.dat", "a+b");
    if(fp == NULL)
        CatchError();
}

/**
 * From fileIO.c
 * 重载文件指针
 */
void ReloadFile()
{
    fseek(fp, 0, SEEK_SET);
}

/**
 * From fileIO.c
 * 关闭文件
 */
void CloseFile()
{
    fclose(fp);
}

/**
 * From fileIO.c
 * 储存数据到文件
 * 
 * GAMEDATA* GP 指向某一游戏模式的数据指针
 * 
 * return int 输入数据数量(正常为1/末尾为0)
 */
int SaveData(GAMEDATA* GP)
{
    return fwrite(GP, sizeof(GAMEDATA), 1, fp);
}

/**
 * From fileIO.c
 * 储存数据到文件
 * 
 * GAMEDATA* GP 指向某一游戏模式的数据指针
 * 
 * return int 提取数据数量(正常为1/末尾为0)
 */
int LoadData(GAMEDATA* GP)
{
    return fread(GP, sizeof(GAMEDATA), 1, fp);
}

/**
 * From fileIO.c
 * 初始化存档
 */
void InitSave()
{
    int i = 0;
    GAMEDATA* TmpLoadData = (GAMEDATA*)malloc(sizeof(GAMEDATA));
    GAMEDATA* TmpUserData = USER->PlayerGameData;
    
    OpenSaveFile();

    if(fp != NULL)
    {
        //将文件指针后退一位，方便feof
        fgetc(fp);

        //根据存档判断是否是第一次游玩
        if(feof(fp))
        {
            ReloadFile();
            for(i=0; i<GameModeNum; i++)
            {
                TmpUserData->WTime = 0;
                TmpUserData->LTime = 0;
                TmpUserData->DTime = 0;
                TmpUserData->GameModeId = i;

                if(i != GameModeNum - 1)
                    TmpUserData->NextGameMode = (GAMEDATA*)calloc(1, sizeof(GAMEDATA));
                else
                    TmpUserData->NextGameMode = NULL;

                SaveData(TmpUserData);

                TmpUserData = TmpUserData->NextGameMode;
            }
        }
        else
        {
            ReloadFile();
            for(i=0; i<GameModeNum; i++)
            {
                if(LoadData(TmpLoadData))
                {
                    TmpUserData->WTime = TmpLoadData->WTime;
                    TmpUserData->LTime = TmpLoadData->LTime;
                    TmpUserData->DTime = TmpLoadData->DTime;
                    TmpUserData->GameModeId = i;
                    if(i+1 != GameModeNum)
                        TmpUserData->NextGameMode = (GAMEDATA*)calloc(1, sizeof(GAMEDATA));
                    else
                        TmpUserData->NextGameMode = NULL;

                    TmpUserData = TmpUserData->NextGameMode;
                }
                else
                    CatchError();
            }
        }
    }
    else
        CatchError();

    free(TmpLoadData);
}

/**
 * From fileIO.c
 * 储存游戏
 */
int SaveGameData()
{
    GAMEDATA* Tmp = NULL;

    CloseFile();
    remove("PlayerSave.dat");
    OpenSaveFile();

    ReloadFile();

    Tmp = USER->PlayerGameData;
    while(Tmp != NULL)
    {
        if(SaveData(Tmp) != 1)
            CatchError();
        Tmp = Tmp->NextGameMode;
    }
}