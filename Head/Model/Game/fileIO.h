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
extern FILE* fp;

/**
 * From fileIO.c
 * ���ļ�
 */
void OpenSaveFile();

/**
 * From fileIO.c
 * �����ļ�ָ��
 */
void ReloadFile();

/**
 * From fileIO.c
 * �ر��ļ�
 */
void CloseFile();

/**
 * From fileIO.c
 * �������ݵ��ļ�
 * 
 * GAMEDATA* GP ָ��ĳһ��Ϸģʽ������ָ��
 * 
 * return int ������������(����Ϊ1/ĩβΪ0)
 */
int SaveData(GAMEDATA* GP);

/**
 * From fileIO.c
 * �������ݵ��ļ�
 * 
 * GAMEDATA* GP ָ��ĳһ��Ϸģʽ������ָ��
 * 
 * return int ��ȡ��������(����Ϊ1/ĩβΪ0)
 */
int LoadData(GAMEDATA* GP);

/**
 * From fileIO.c
 * ��ʼ���浵
 */
void InitSave();

/**
 * From fileIO.c
 * ������Ϸ
 */
int SaveGameData();