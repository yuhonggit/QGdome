#include "../head/linkedList.h"
#include<stdlib.h>
#include<stdio.h>


/*             LinkedList和LNode*是一样的           */

/**
 *  @name        : Status InitList(LinkList *L);
 *      @description : initialize an empty linked list with only the head node without value    用没有值的头结点初始化空链接列表
 *      @param           : L(the head node)
 *      @return          : Status
 *  @notice      : None
 */
Status InitList ( LinkedList *L )
{
	//L是指向一级指针LinkedList的二级指针*L对应就是LinkedList
	//头结点是空的不影响后面的创建链表列表
	*L = ( LinkedList* ) malloc ( sizeof ( LinkedList ) );//分配内存
	( *L )->next = NULL;//下一个指针域指向空
	if ( *L == NULL )
		return SUCCESS;
	else
		return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *      @description : destroy a linked list, free all the nodes     销毁链接列表，释放所有结点
 *      @param           : L(the head node)
 *      @return          : None
 *  @notice      : None
 */
void DestroyList ( LinkedList *L )
{
	//是先销毁了链表的头，然后接着一个一个的把后面的销毁了，这样这个链表就不能再使用了，即把包括头的所有结点全部释放
	LinkedList pnode;  //声明一个临时指针变量q
	while ( *L != NULL ) //while(*L)就是非0执行0就不执行
	{
		pnode = ( *L )->next; //pnode是结节点的指针域,而指针域指向下一个结点的数字域
		free ( *L ); //删除头节点的数字域
		*L = pnode; //这时为新头节点
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *      @description : insert node q after node p     在结点p后插入结点q
 *      @param           : p, q
 *      @return          : Status
 *  @notice      : None
 */
Status InsertList ( LNode *p, LNode *q ) //p和q是结构体指针
{
	//判断p是不是最后一个结点
	LinkedList h;
	LNode*pro,*in;
	pro = h;
	in=q;
	while(pro->data!=p->data)
	{


	if ( pro->next == NULL )
	{
		in=pro->next;
	}
	else
	{
		pro->next = in->next; //把p的指针域给q的指针域,就是p的指针域指向下一个数字域给q
		in = pro->next;//q的数字域就是p的指针域所指向
	}
	}
	return SUCCESS;
//	if ( p->next == NULL )
//	{
//		q=p->next;
//	}
//	else
//	{
//		p->next = q->next; //把p的指针域给q的指针域,就是p的指针域指向下一个数字域给q
//		q = p->next;//q的数字域就是p的指针域所指向
//	}

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *      @description : delete the first node after the node p and assign its value to e    删除结点p之后的第一个结点，并将其值赋给e
 *      @param           : p, e
 *      @return          : Status
 *  @notice      : None
 */
Status DeleteList ( LNode *p, ElemType *e )
{

	LNode  *pos, *pre;                 //pre为前驱结点，pos为查找的结点。
	pos = p->next;
	while ( pos->data != ( *e ) )           //循环查找值为*e的元素
	{
		pre = pos;
		pos = pos->next;
	}
	pre->next = pos->next;          //删除操作，将其前驱next指向其后继。
	free ( pos );
	return SUCCESS;




}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *      @description : traverse the linked list and call the funtion visit      遍历链接列表并调用函数访问
 *      @return          : None
 *  @notice      : None
 */
void TraverseList ( LinkedList L, void ( *visit ) ( ElemType e ) )
{
	//
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *      @description : find the first node in the linked list according to e      根据e查找链接列表中的第一个结点
 *      @param           : L(the head node), e
 *      @return          : Status
 *  @notice      : None
 */
/*Status SearchList ( LinkedList L, ElemType e )
{

*/

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *      @description : reverse the linked list     反转链接列表
 *      @param           : L(the head node)
 *      @return          : Status
 *  @notice      : None
 */
/*Status ReverseList ( LinkedList *L )
{

}*/

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *      @description : judge whether the linked list is looped     判断链表是否循环
 *      @param           : L(the head node)
 *      @return          : Status
 *  @notice      : None
 */
/*Status IsLoopList ( LinkedList L )
{

}*/

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *      @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3  反转链表列表中值为偶数的结点
 *      @param           : L(the head node)
 *      @return          : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList ( LinkedList *L )
{


	if ( ( *L ) == NULL )
	{
		printf ( "链表为空\n" );
		return NULL ;
	}

	if ( ( *L )->next == NULL )
		return ( *L ); //链表队列只有一个元素时候就直接返回
	//若是有两个以上，则：
	LNode* phead = ( *L );
	LNode* temp = ( *L )->next;
	while ( temp != NULL ) //循环直到temp为空
	{
		//实现偶数交换
		LNode* pNext = temp->next;
		temp->next = ( *L );
		( *L ) = temp;
		temp = pNext;
	}
	phead->next = NULL;
	return ( *L );

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *      @description : find the middle node in the linked list    找到链表的中间结点
 *      @param           : L(the head node)
 *      @return          : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode ( LinkedList *L )
{
	//快慢指针，快指针走两步慢指针走一步，循环判断快指针是不是走到NULL，当走到NULL，慢指针走到中点
	LNode*fast, *slow; //快指针和慢指针
	fast = *L;
	slow = *L;
	if ( *L == NULL )
		printf ( "链表为空，无法找到中点\n" );
	else
	{

		//              while ( fast != NULL )
		//              {
		//                      if ( fast->next == NULL )
		//                      {
		//                              printf ( "中间结点是%d", slow->data );
		//                              return;
		//                      }
		//                      if(fast->next->next==NULL)
		//                      {
		//                              printf("中间结点是%d\t%d\n",slow->data,slow->next->data);
		//                              return;
		//                      }
		//
		//                      slow = slow->next;
		//                      fast = fast->next->next;
		//
		//              }


		while ( fast->next != NULL && fast->next->next != NULL )
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		printf ( "中间数是%d", slow->next->data );

	

	}
	return SUCCESS;
}
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *      @description :   创建列表
 *      @param           : L(the head node)
 *      @return          : LNode
 *  @notice      : choose to finish
 */

LinkedList LinkedListCreatH()
{

	LNode *L;
	L = ( LNode * ) malloc ( sizeof ( LNode ) ); //申请头结点L空间
	L->next = NULL;                  //初始化一个空链表
	LNode *r;                        //
	r = L;                          //r始终指向终端结点，开始时指向头结点
	ElemType x;                         //x为链表数据域中的数据
	int count;
	printf("please input the  node number is\n");
	scanf_s("%d", &count);
	printf("please input the per node number(Press the space for each confirmation,when you confirm everything,enter)\n");
	for(int i=1;i<=count;i++)
	{
		LNode *p;
		p = ( LNode * ) malloc ( sizeof ( LNode ) );
		scanf_s("%d",&x);
		p->data = x;                     //结点数据域赋值
		r->next = p;                 //将结点插入到表头L-->|1|-->|2|-->NULL
		r = p;

	}

	r->next = NULL;

	return L;

}

/*
LinkedList Creat_list(LinkedList head) {
	head = (LinkedList)malloc(sizeof(LNode));      //  为头指针开辟内存空间
	LNode *node = NULL;                    //  定义新结点
	int count = 0;                          //  创建结点的个数
	head->next = NULL;
	node = head->next;              	//  将最后一个结点的指针域永远保持为NULL
	printf("please input the  node number is\n");
	scanf("%d", &count);
	int num;
	printf("please input the per node number(Press the space for each confirmation,when you confirm everything,enter)\n");
	for (int i = 0; i < count; i++)
	{
		node = (LinkedList)malloc(sizeof(node));     //  为新结点开辟内存空间
		scanf("%d",&num);
		node->data = num;               //  为新结点的数据域赋值
		node->next = head->next;          //  将头指针所指向的下一个结点的地址，赋给新创建结点的next
		head->next = node;          //  将新创建的结点的地址赋给头指针的下一个结点
	}
	return head;
}*/
