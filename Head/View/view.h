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
void ViewHead();

/**
 * From view.c
 * ����β����ͼ
 */
void ViewFoot();

/**
 * From view.c
 * ����ѡ����ͼ
 */
void ViewChoose(int ModeCode, int PageCode);

/**
 * From view.c
 * ��������չʾ��ͼ
 */
void ViewShowData(GAMEDATA* PlayerData);

/**
 * From view.c
 * �����˳�ҳ��
 */
void ViewExit();

/**
 * From view.c
 * ���徯��β��
 */
void ViewPrompt(char* PromptStr);

/**
 * From view.c
 * �������ҳ������
 */
void ViewErrorBody();

/**
 * From view.c
 * �������ҳ��β��
 */
void ViewErrorFoot();