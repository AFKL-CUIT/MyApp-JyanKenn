#ifndef __MAIN_HEAD__
    #include "main.h"
#endif

/*
���ﶨ������Ϸ����ϸ�ڵ�����
*/

/**
 * From gameReferee.c
 * ������ÿ����Ϸ��ÿ�غ���Ӯ״̬�ͻغ���
 * 
 * PLAYER* WinPlayer ʤ�����
 * |char| PunchValue_Win ʤ����ҵĳ�ȭ
 * 
 * PLAYER* LosePlayer ʧ�����
 * |char| PunchValue_Lose ʧ����ҳ�ȭ
 * 
 * |int| GameTimes ��Ϸ����
 * |int| RoundTimes �غ���
 */
typedef struct Times TIMES;

extern TIMES* ThisGame;

/**
 * From gameReferee.c
 * ���嵱ǰ��Ϸģʽ�Ĵ���
 */
extern int ModeCode;

/**
 * From gameReferee.c
 * �����˲�ͬ��ȭֵ������
 */
extern const char* PunchName[3];

/**
 * From gameReferee.c
 * ��¼��ȭ
 * 
 * PUNCH* TmpPunch Ҫ��¼�ĳ�ȭ
 * PLAYER* TmpPlayer ����¼�����
 */
void NotePunch(PUNCH*, PLAYER*);

/**
 * From gameReferee.c
 * ��¼���ս��
 */
void NoteGameData(PLAYER*);

/**
 * From gameReferee.c
 * ������Ĳ��ֺ�����(��Χ0~2)
 * 
 * return int RandValue;
 */
int RandNum();

/**
 * From gameReferee.c
 * ʤ�����������
 */
void WinPlayer(TIMES*, PLAYER*, unsigned char);

/**
 * From gameReferee.c
 * ʧ���������
 */
void LosePlayer(TIMES*, PLAYER*, unsigned char);

/**
 * From gameReferee.c
 * ������ʤ���ж�
 * 
 * TIMES* Games ������Ϸ
 * PLAYER* P1 ���1
 * int Punch1 ���1���غϳ�ȭ
 * PLAYER* P2 ���2
 * int Punch1 ���1���غϳ�ȭ
 * 
 * return PLAYER* WinP ʤ������ң�ƽ�ַ���NULL
 */
PLAYER* JudgeWinAndLose(TIMES*, PLAYER*, int, PLAYER*, int);

/**
 * From gameReferee.c
 * ����ҽ��п�Ѫ
 */
int DeductHP(PLAYER*, unsigned int);
/**
 * From gameReferee.c
 * ��ճ�ȭ����
 * 
 * PLAYER* PlayerPunchLink
 */
void UnLinkPunch(PLAYER*);

/**
 * From gameReferee.c
 * ����Ϸ����ʱ:
 * 1. ��ճ�ȭ����
 * 2. ��ʼ��GameTimes
 * 3. ��¼ս��
 */
void GameOver();