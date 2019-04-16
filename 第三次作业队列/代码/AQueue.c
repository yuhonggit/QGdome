#include <AQueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue ( AQueue *Q )
{
	//循环分配空间
	for ( int i = 0; i < MAXQUEUE; i++ )
	{
		Q->data[i] = ( void* ) malloc ( sizeof ( void* ) ); //给空void类型就是说明用户可以指定用户输入任何类型
		Q->data[i] = NULL;
	}
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;


}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue ( AQueue *Q )
{
	//循环释放空间
	int i;
	for ( i = 0; i < MAXQUEUE; i++ )
	{
		free ( Q->data[i] ); //不管队列有多少元素反正全部删了就行
		Q->data[i] = NULL;
	}


}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue ( AQueue *Q, void *e )
{
	//先判断队列是不是空，刚刚的IsEmptyAQueue函数判断了返回TRUE=1就是空，返回FALSE=0就不是空
	if ( Q->length == 0 )
	{
		printf ( "The queue is empty,There is no header element\n" );
		return FALSE;
	}

	//由于两个数是不同类型的,用memcpy函数就可以这两个占不同内存的两个元素交换
	//memcpy函数的功能是从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中
	else
	{
		int index;
		//index = ( Q->front + 1 ) % MAXQUEUE; //这是循环队列来的
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue ( AQueue *Q )
{
	//返回长度
	return Q->length;

}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue ( AQueue *Q, void *data )
{
	//先判断队列是不是满的
	if ( Q->length == MAXQUEUE )
	{
		printf ( "The queue is full，You can't insert elements\n" );
		return FALSE;
	}
	else
	{
		Q->rear = ( Q->rear  ) % MAXQUEUE; //因为这是循环队列的，所以不可以直接+1
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue ( AQueue *Q )
{
	//先判断函数是不是空
	if ( Q->length == 0 )
	{
		printf ( "The queue is empty,can't remove the element in the queue!!!\n" );
		return FALSE;
	}
	//千万不要把这个位置内存清空，把这个位置的元素放在这里就行，到时候入队再把这个元素覆盖掉
	//free(Q->data[Q->front]);
	else
	{
		free ( Q->data[Q->front] ); //释放掉这个内存但是空间还在
		Q->data[Q->front] = NULL;
		Q->front = ( Q->front + 1 ) % MAXQUEUE;//往后移动一位
		Q->length--;
		printf ( "Remove the element successfully!\n" );

		return TRUE;
	}


}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue ( AQueue *Q )
{
	//先判断队列是不是空的，空的就不用清除
	if ( Q->front == Q->rear )
	{
		printf ( "The queue is empty\n" );
		return ;//返回不带值

	}
	else
	{
		//队头和队尾都指向0
		Q->front = 0;
		Q->rear = 0;
		Q->length = 0;
		printf ( "Empty the success\n" );
		return;//返回不带值
	}


}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue ( const AQueue *Q, void ( *foo ) ( void *q ) ) //遍历函数顺便调用Aprint函数
{
	//      //判断队列是不是空的
	//      if ( Q->front == Q->rear )
	//      {
	//              printf ( "The empty is empty\n" );
	//              return FALSE;
	//      }
	//      //不是空->
	//      int i = Q->front + 1;
	//      while ( i <= ( MAXQUEUE - Q->front + Q->rear ) % MAXQUEUE )
	//      {
	//              foo ( Q->data[i], Q->length );
	//              i = ( i + 1 ) % MAXQUEUE;
	//      }
	//      printf ( "\n" );
	//      return TRUE;
	//判断队列是不是空
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
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint_top ( void *q ) //就是把每个类型输出,q是数据
{
	//      if ( size == sizeof ( double ) )
	//              printf ( "%lf", * ( double * ) q );
	//      if ( size == sizeof ( char ) )
	//              printf ( "%c", * ( char * ) q );
	//      if ( size == sizeof ( int ) )
	//              printf ( "%d", * ( int * ) q );
	//      printf ( "-<" );
	//void* 指针为空，返回
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
