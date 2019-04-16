
/***************************************************************************************
 *    File Name                :    AQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2019.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED


/**************************************************************
 *    Macro Define Section
 **************************************************************/

#include <crtdefs.h>
#define MAXQUEUE 10//������鳤��
#define MAX_STRINGS_LENGTH 100
#define INF 20002000

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//ѭ�����нṹ
//typedef unsigned size_t;

typedef struct DATA{
	int type;
	int integer;
	double real_number;
	char character;


}Type;
typedef struct Aqueue
{

    void *data[MAXQUEUE];      //������
    int front;		//frontָ���ͷԪ�ص������±�
    int rear;		//rearָ���βԪ�ص���һ��λ�õ������±�,����rear��Ӱ�±�������е�Ԫ���ǿյ�
    /*	1.�����������������ʽ�洢
	2.��Q->front=Q->rearʱ�ǿ��б����˼
	3.��front��rearָ��0���ǳ�ʼ��������Ϊ0
	4.front��Զָ��0����ӵ�ʱ��rear+1�����ӵ�ʱ��rear-1������ѭ����ǰ�棩
	5.�ж϶���Ϊ��������һ��λ�ò��������֣�
	��Q->front == (Q->rear + 1) % MAXQUEUE��������
	6.�ж϶��еĳ���
	��ʽ�� long=(Q->rear - Q->front + MAXQUEUE) % MAXQUEUE
    */
    size_t length;        //���г���
} AQueue;

//struct DATA
//{
//	int select;
//	int data_int;
//	double data_double;
//	char data_char;
//	int data_size;
//}type;
typedef enum
{
    FALSE=0, TRUE=1
} Status;


/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q);


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q);



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q);

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q);



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e);



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q);



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data);



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q);



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q);



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue ( const AQueue *Q, void ( *foo ) ( void *q ) );



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q);
void APrint_top ( void *q );

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED

