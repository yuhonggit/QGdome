#include <AQueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue ( AQueue *Q )
{
	//ѭ������ռ�
	for ( int i = 0; i < MAXQUEUE; i++ )
	{
		Q->data[i] = ( void* ) malloc ( sizeof ( void* ) ); //����void���;���˵���û�����ָ���û������κ�����
		Q->data[i] = NULL;
	}
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;


}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue ( AQueue *Q )
{
	//ѭ���ͷſռ�
	int i;
	for ( i = 0; i < MAXQUEUE; i++ )
	{
		free ( Q->data[i] ); //���ܶ����ж���Ԫ�ط���ȫ��ɾ�˾���
		Q->data[i] = NULL;
	}


}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue ( const AQueue *Q )
{
	if ( Q->length == MAXQUEUE )
	{
		printf ( "The queue is full\n" );
		return TRUE;
	}
	else
	{
		printf ( "The queue is not full\n" );
		return FALSE;
	}


}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue ( const AQueue *Q )
{
	//      if ( Q->front == Q->rear )
	//      {
	//              printf ( "The queue is empty\n" );
	//              return TRUE;
	//      }
	//      else
	//      {
	//              printf ( "The queue is not empty\n" );
	//              return FALSE;
	//      }
	if ( Q->length == 0 )
	{
		printf ( "The queue is empty\n" );
		return TRUE;
	}
	else
	{
		printf ( "The queue is not empty\n" );
		return FALSE;
	}

}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue ( AQueue *Q, void *e )
{
	//���ж϶����ǲ��ǿգ��ոյ�IsEmptyAQueue�����ж��˷���TRUE=1���ǿգ�����FALSE=0�Ͳ��ǿ�
	if ( Q->length == 0 )
	{
		printf ( "The queue is empty,There is no header element\n" );
		return FALSE;
	}

	//�����������ǲ�ͬ���͵�,��memcpy�����Ϳ���������ռ��ͬ�ڴ������Ԫ�ؽ���
	//memcpy�����Ĺ����Ǵ�Դ�ڴ��ַ����ʼλ�ÿ�ʼ�������ɸ��ֽڵ�Ŀ���ڴ��ַ��
	else
	{
		int index;
		//index = ( Q->front + 1 ) % MAXQUEUE; //����ѭ����������
		index = Q->front ;
		* ( Type * ) e = * ( ( Type * ) ( Q->data[index] ) );
		return TRUE;
	}

	//      memcpy ( e, Q->data[index], Q->length );
	//      if (sizeof(e)==4)
	//      {
	//              printf("%d",* ( int * ) e);
	//      }
	//      else if (sizeof(e)==8)
	//      {
	//              printf("%lf",* ( double * ) e);
	//      }
	//      else if (sizeof(e)==10)
	//      {
	//              printf("%s",* ( char * ) e);
	//      }
	//      return TRUE;

}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue ( AQueue *Q )
{
	//���س���
	return Q->length;

}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue ( AQueue *Q, void *data )
{
	//���ж϶����ǲ�������
	if ( Q->length == MAXQUEUE )
	{
		printf ( "The queue is full��You can't insert elements\n" );
		return FALSE;
	}
	else
	{
		Q->rear = ( Q->rear  ) % MAXQUEUE; //��Ϊ����ѭ�����еģ����Բ�����ֱ��+1
		//memcpy ( Q->data[Q->rear], data, Q->length );
		Q->data[Q->rear] = data;
		Q->rear++;
		Q->length++;
		printf ( "Insert successfully!\n" );
		return TRUE;
	}

}





/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue ( AQueue *Q )
{
	//���жϺ����ǲ��ǿ�
	if ( Q->length == 0 )
	{
		printf ( "The queue is empty,can't remove the element in the queue!!!\n" );
		return FALSE;
	}
	//ǧ��Ҫ�����λ���ڴ���գ������λ�õ�Ԫ�ط���������У���ʱ������ٰ����Ԫ�ظ��ǵ�
	//free(Q->data[Q->front]);
	else
	{
		free ( Q->data[Q->front] ); //�ͷŵ�����ڴ浫�ǿռ仹��
		Q->data[Q->front] = NULL;
		Q->front = ( Q->front + 1 ) % MAXQUEUE;//�����ƶ�һλ
		Q->length--;
		printf ( "Remove the element successfully!\n" );

		return TRUE;
	}


}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue ( AQueue *Q )
{
	//���ж϶����ǲ��ǿյģ��յľͲ������
	if ( Q->front == Q->rear )
	{
		printf ( "The queue is empty\n" );
		return ;//���ز���ֵ

	}
	else
	{
		//��ͷ�Ͷ�β��ָ��0
		Q->front = 0;
		Q->rear = 0;
		Q->length = 0;
		printf ( "Empty the success\n" );
		return;//���ز���ֵ
	}


}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue ( const AQueue *Q, void ( *foo ) ( void *q ) ) //��������˳�����Aprint����
{
	//      //�ж϶����ǲ��ǿյ�
	//      if ( Q->front == Q->rear )
	//      {
	//              printf ( "The empty is empty\n" );
	//              return FALSE;
	//      }
	//      //���ǿ�->
	//      int i = Q->front + 1;
	//      while ( i <= ( MAXQUEUE - Q->front + Q->rear ) % MAXQUEUE )
	//      {
	//              foo ( Q->data[i], Q->length );
	//              i = ( i + 1 ) % MAXQUEUE;
	//      }
	//      printf ( "\n" );
	//      return TRUE;
	//�ж϶����ǲ��ǿ�
	if ( Q->length == 0 )
	{
		printf ( "The queue is empty\n" );
		return FALSE;
	}
	else
	{
		int i = Q->front ;
		while ( i <= ( Q->rear ) % MAXQUEUE )
		{
			foo ( Q->data[i] );
			i = ( i + 1 ) % MAXQUEUE;
		}
		return TRUE;
	}


}



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint_top ( void *q ) //���ǰ�ÿ���������,q������
{
	//      if ( size == sizeof ( double ) )
	//              printf ( "%lf", * ( double * ) q );
	//      if ( size == sizeof ( char ) )
	//              printf ( "%c", * ( char * ) q );
	//      if ( size == sizeof ( int ) )
	//              printf ( "%d", * ( int * ) q );
	//      printf ( "-<" );
	//void* ָ��Ϊ�գ�����
	if ( q == NULL )
		return;
	Type *temp = ( Type * ) q;

	if ( temp->type == 1 )
	{
		printf ( "%d", temp->integer );
	}
	else if ( temp->type == 2 )
	{
		printf ( "%.2lf", temp->real_number );
	}
	else if ( temp->type == 3 )
	{
		printf ( "%c", temp->character );

	}



}

void APrint ( void*q )
{
	if ( q == NULL )
		return;
	Type *temp = ( Type * ) q;

	if ( temp->type == 1 )
	{
		printf ( "%d->", temp->integer );
	}
	else if ( temp->type == 2 )
	{
		printf ( "%.2lf->", temp->real_number );
	}
	else if ( temp->type == 3 )
	{
		printf ( "%c->", temp->character );

	}
}
