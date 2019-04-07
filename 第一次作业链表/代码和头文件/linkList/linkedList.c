#include "../head/linkedList.h"
#include<stdlib.h>
#include<stdio.h>


/*             LinkedList��LNode*��һ����           */

/**
 *  @name        : Status InitList(LinkList *L);
 *      @description : initialize an empty linked list with only the head node without value    ��û��ֵ��ͷ����ʼ���������б�
 *      @param           : L(the head node)
 *      @return          : Status
 *  @notice      : None
 */
Status InitList ( LinkedList *L )
{
	//L��ָ��һ��ָ��LinkedList�Ķ���ָ��*L��Ӧ����LinkedList
	//ͷ����ǿյĲ�Ӱ�����Ĵ��������б�
	*L = ( LinkedList* ) malloc ( sizeof ( LinkedList ) );//�����ڴ�
	( *L )->next = NULL;//��һ��ָ����ָ���
	if ( *L == NULL )
		return SUCCESS;
	else
		return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *      @description : destroy a linked list, free all the nodes     ���������б��ͷ����н��
 *      @param           : L(the head node)
 *      @return          : None
 *  @notice      : None
 */
void DestroyList ( LinkedList *L )
{
	//���������������ͷ��Ȼ�����һ��һ���İѺ���������ˣ������������Ͳ�����ʹ���ˣ����Ѱ���ͷ�����н��ȫ���ͷ�
	LinkedList pnode;  //����һ����ʱָ�����q
	while ( *L != NULL ) //while(*L)���Ƿ�0ִ��0�Ͳ�ִ��
	{
		pnode = ( *L )->next; //pnode�ǽ�ڵ��ָ����,��ָ����ָ����һ������������
		free ( *L ); //ɾ��ͷ�ڵ��������
		*L = pnode; //��ʱΪ��ͷ�ڵ�
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *      @description : insert node q after node p     �ڽ��p�������q
 *      @param           : p, q
 *      @return          : Status
 *  @notice      : None
 */
Status InsertList ( LNode *p, LNode *q ) //p��q�ǽṹ��ָ��
{
	//�ж�p�ǲ������һ�����
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
		pro->next = in->next; //��p��ָ�����q��ָ����,����p��ָ����ָ����һ���������q
		in = pro->next;//q�����������p��ָ������ָ��
	}
	}
	return SUCCESS;
//	if ( p->next == NULL )
//	{
//		q=p->next;
//	}
//	else
//	{
//		p->next = q->next; //��p��ָ�����q��ָ����,����p��ָ����ָ����һ���������q
//		q = p->next;//q�����������p��ָ������ָ��
//	}

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *      @description : delete the first node after the node p and assign its value to e    ɾ�����p֮��ĵ�һ����㣬������ֵ����e
 *      @param           : p, e
 *      @return          : Status
 *  @notice      : None
 */
Status DeleteList ( LNode *p, ElemType *e )
{

	LNode  *pos, *pre;                 //preΪǰ����㣬posΪ���ҵĽ�㡣
	pos = p->next;
	while ( pos->data != ( *e ) )           //ѭ������ֵΪ*e��Ԫ��
	{
		pre = pos;
		pos = pos->next;
	}
	pre->next = pos->next;          //ɾ������������ǰ��nextָ�����̡�
	free ( pos );
	return SUCCESS;




}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *      @description : traverse the linked list and call the funtion visit      ���������б����ú�������
 *      @return          : None
 *  @notice      : None
 */
void TraverseList ( LinkedList L, void ( *visit ) ( ElemType e ) )
{
	//
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *      @description : find the first node in the linked list according to e      ����e���������б��еĵ�һ�����
 *      @param           : L(the head node), e
 *      @return          : Status
 *  @notice      : None
 */
/*Status SearchList ( LinkedList L, ElemType e )
{

*/

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *      @description : reverse the linked list     ��ת�����б�
 *      @param           : L(the head node)
 *      @return          : Status
 *  @notice      : None
 */
/*Status ReverseList ( LinkedList *L )
{

}*/

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *      @description : judge whether the linked list is looped     �ж������Ƿ�ѭ��
 *      @param           : L(the head node)
 *      @return          : Status
 *  @notice      : None
 */
/*Status IsLoopList ( LinkedList L )
{

}*/

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *      @description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3  ��ת�����б���ֵΪż���Ľ��
 *      @param           : L(the head node)
 *      @return          : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList ( LinkedList *L )
{


	if ( ( *L ) == NULL )
	{
		printf ( "����Ϊ��\n" );
		return NULL ;
	}

	if ( ( *L )->next == NULL )
		return ( *L ); //�������ֻ��һ��Ԫ��ʱ���ֱ�ӷ���
	//�������������ϣ���
	LNode* phead = ( *L );
	LNode* temp = ( *L )->next;
	while ( temp != NULL ) //ѭ��ֱ��tempΪ��
	{
		//ʵ��ż������
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
 *      @description : find the middle node in the linked list    �ҵ�������м���
 *      @param           : L(the head node)
 *      @return          : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode ( LinkedList *L )
{
	//����ָ�룬��ָ����������ָ����һ����ѭ���жϿ�ָ���ǲ����ߵ�NULL�����ߵ�NULL����ָ���ߵ��е�
	LNode*fast, *slow; //��ָ�����ָ��
	fast = *L;
	slow = *L;
	if ( *L == NULL )
		printf ( "����Ϊ�գ��޷��ҵ��е�\n" );
	else
	{

		//              while ( fast != NULL )
		//              {
		//                      if ( fast->next == NULL )
		//                      {
		//                              printf ( "�м�����%d", slow->data );
		//                              return;
		//                      }
		//                      if(fast->next->next==NULL)
		//                      {
		//                              printf("�м�����%d\t%d\n",slow->data,slow->next->data);
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
		printf ( "�м�����%d", slow->next->data );

	

	}
	return SUCCESS;
}
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *      @description :   �����б�
 *      @param           : L(the head node)
 *      @return          : LNode
 *  @notice      : choose to finish
 */

LinkedList LinkedListCreatH()
{

	LNode *L;
	L = ( LNode * ) malloc ( sizeof ( LNode ) ); //����ͷ���L�ռ�
	L->next = NULL;                  //��ʼ��һ��������
	LNode *r;                        //
	r = L;                          //rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ���
	ElemType x;                         //xΪ�����������е�����
	int count;
	printf("please input the  node number is\n");
	scanf_s("%d", &count);
	printf("please input the per node number(Press the space for each confirmation,when you confirm everything,enter)\n");
	for(int i=1;i<=count;i++)
	{
		LNode *p;
		p = ( LNode * ) malloc ( sizeof ( LNode ) );
		scanf_s("%d",&x);
		p->data = x;                     //���������ֵ
		r->next = p;                 //�������뵽��ͷL-->|1|-->|2|-->NULL
		r = p;

	}

	r->next = NULL;

	return L;

}

/*
LinkedList Creat_list(LinkedList head) {
	head = (LinkedList)malloc(sizeof(LNode));      //  Ϊͷָ�뿪���ڴ�ռ�
	LNode *node = NULL;                    //  �����½��
	int count = 0;                          //  �������ĸ���
	head->next = NULL;
	node = head->next;              	//  �����һ������ָ������Զ����ΪNULL
	printf("please input the  node number is\n");
	scanf("%d", &count);
	int num;
	printf("please input the per node number(Press the space for each confirmation,when you confirm everything,enter)\n");
	for (int i = 0; i < count; i++)
	{
		node = (LinkedList)malloc(sizeof(node));     //  Ϊ�½�㿪���ڴ�ռ�
		scanf("%d",&num);
		node->data = num;               //  Ϊ�½���������ֵ
		node->next = head->next;          //  ��ͷָ����ָ�����һ�����ĵ�ַ�������´�������next
		head->next = node;          //  ���´����Ľ��ĵ�ַ����ͷָ�����һ�����
	}
	return head;
}*/
