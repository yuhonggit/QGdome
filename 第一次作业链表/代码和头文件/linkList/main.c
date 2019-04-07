
#include <stdio.h>
#include <stdlib.h>
#include "F:/qg/代码和头文件/head/linkedList.h"
//输出链表
void PrintList ( LinkedList head ) //打印当前链表
{
	LNode *p = head->next;
	int counter = 0;
	if ( p == NULL )
		printf ( "链表为空\n" );
	else
	{
		while ( p != NULL )
		{

			
		}
	}
	printf ( "\n当前有%d个结点\n", counter );


}
/*
Status ListInsert_L ( LinkList &L, int i, int e )
{
        LinkList p = L;
        int j = 0;
        while ( p && j < i - 1 ) //找到第i-1个位置
        {
                p = p->next;
                j += 1;
        }
        if ( j > i - 1 || !p )
                return ERROR; //i的位置不合法时,即i=0或i>Length(L)+1(表长加1)
        LinkList q = ( LinkList ) malloc ( sizeof ( LNode ) ); //动态开辟新的结点
        q->data = e;   //将e的值赋给新的结点
        q->next = p->next;
        p->next = q; //在i-1位置之后插入新的结点
        return OK;
}*/

LinkedList LinkedListInsert ( LinkedList L, int i, ElemType x )
{
	LNode *pre;        //pre为前驱结点
	pre = L;
	int tempi = 0;
	for ( tempi = 1; tempi < i; tempi++ )
	{
		pre = pre->next;    //查找第i位置的前驱结点
	}
	LNode *p;        //插入结点为p；
	p = ( LNode * ) malloc ( sizeof ( LNode ) );
	p->data = x;
	p->next = pre->next;
	pre->next = p;
	return L;
}

int main()
{

	while ( 1 )
	{
		
		//检测用户输入是否在1到8之间
		int choice;
		scanf ( "%d", &choice );
		/*int choice = -1;
		int a = 1;
		printf ( "请输入你的选择" );
		while ( 1 )
		{
		        scanf ( "%d", &choice );
		        if ( choice >= 1 && choice <= 7 )
		        {
		                printf ( "\n****你输入的结果是%d   ****\n", choice );
		                printf ( "\n" );
		                break;
		        }
		        else
		        {
		                fflush ( stdin ); //清除数据
		                printf ( "字符非法，请重新输入\n" );
		        }
		}*/


		LinkedList list, start, L;
		LNode*q, *p;

		ElemType num, num1, num_index, num_insert, middle, num2;


		if ( choice == 1 ) //ok
		{

			InitList ( &list );  //初始化列表


			/*收集并存储数据*/
			puts ( "==>请输入数据。注意：每输入一个数就按空格键然后输入下一个，当确认时就按enter+ctrl+z+enter" );
			list = LinkedListCreatH();
			printf ( "\n当前链表队列为\n" );
			PrintList ( list );


		}
		else if ( choice == 2 ) //删除元素
		{


			printf ( "请输入你要删除的数\n" );
			scanf ( "%d", &num );
			DeleteList ( list, &num );
			printf ( "删除成功!!\n" );


		}
		else if ( choice == 3 ) //插入元素
		{
			//                      printf("请输入在哪个结点后加元素\n");
			//                      scanf("%d",&num1);
			//                      printf("加入的元素是\n");
			//                      scanf("%d",&num_insert);
			//                      InsertList(&num1,&num_insert);
			//                      printf("\n当前链表队列为\n");
			//                      for ( start = list->next; start != NULL; start = start->next )
			//                      {
			//                              printf ( "%d ", start->data );
			//                      }
			/*int push_data, push_i;
			printf ( "输入你想要插入的元素和它的插入位置：\n" );

			scanf ( "%d%d", &push_data, &push_i );

			Push_L ( L, push_data, push_i );
			printf ( "插入后的链表遍历为：\n" );
			Traverse_L ( L );*/
			int i;
			printf ( "请输入插入数据的位置\n" );
			scanf ( "%d", &i );
			printf ( "请输入值以插入数据\n" );
			scanf ( "%d", &num );
			LinkedListInsert ( list, i, num );

			printf ( "新的队列是\n" );

			PrintList ( list );

		}
		else if ( choice == 4 ) //ok
		{
			DestroyList ( &list );
			printf ( "清空链表成功！！\n" );


		}
		else if ( choice == 5 ) //ok
		{
			PrintList ( list );
		}
		else if ( choice == 6 ) //ok
		{
			FindMidNode ( &list );

		}
		else if ( choice == 7 )
		{
			list = ReverseEvenList ( &list );
			printf ( "偶数队列调换后的结果是\n" );
			PrintList ( list );
		}

	}
}
