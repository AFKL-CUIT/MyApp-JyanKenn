#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

extern FILE* fp;

void OpenSaveFile();

void ReloadFile();

void CloseFile();

int SaveData(GAMEDATA* GP);

int LoadData(GAMEDATA* GP);

void InitSave();

int UpdateGameData();