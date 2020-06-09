#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
�����ļ�����
*/

/**
 * From fileIO.c
 * ����浵���ļ�ָ��
 */
FILE* fp = NULL;

/**
 * From fileIO.c
 * ���ļ�
 */
void OpenSaveFile()
{
    fp = fopen("PlayerSave.dat", "a+b");
    if(fp == NULL)
        CatchError();
}

/**
 * From fileIO.c
 * �����ļ�ָ��
 */
void ReloadFile()
{
    fseek(fp, 0, SEEK_SET);
}

/**
 * From fileIO.c
 * �ر��ļ�
 */
void CloseFile()
{
    fclose(fp);
}

/**
 * From fileIO.c
 * �������ݵ��ļ�
 * 
 * GAMEDATA* GP ָ��ĳһ��Ϸģʽ������ָ��
 * 
 * return int ������������(����Ϊ1/ĩβΪ0)
 */
int SaveData(GAMEDATA* GP)
{
    return fwrite(GP, sizeof(GAMEDATA), 1, fp);
}

/**
 * From fileIO.c
 * �������ݵ��ļ�
 * 
 * GAMEDATA* GP ָ��ĳһ��Ϸģʽ������ָ��
 * 
 * return int ��ȡ��������(����Ϊ1/ĩβΪ0)
 */
int LoadData(GAMEDATA* GP)
{
    return fread(GP, sizeof(GAMEDATA), 1, fp);
}

/**
 * From fileIO.c
 * ��ʼ���浵
 */
void InitSave()
{
    int i = 0;
    GAMEDATA* TmpLoadData = (GAMEDATA*)malloc(sizeof(GAMEDATA));
    GAMEDATA* TmpUserData = USER->PlayerGameData;
    
    OpenSaveFile();

    if(fp != NULL)
    {
        //���ļ�ָ�����һλ������feof
        fgetc(fp);

        //���ݴ浵�ж��Ƿ��ǵ�һ������
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
 * ������Ϸ
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