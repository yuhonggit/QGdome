
#include <stdio.h>
#include <stdlib.h>
#include "F:/qg/�����ͷ�ļ�/head/linkedList.h"
//�������
void PrintList ( LinkedList head ) //��ӡ��ǰ����
{
	LNode *p = head->next;
	int counter = 0;
	if ( p == NULL )
		printf ( "����Ϊ��\n" );
	else
	{
		while ( p != NULL )
		{

			
		}
	}
	printf ( "\n��ǰ��%d�����\n", counter );


}
/*
Status ListInsert_L ( LinkList &L, int i, int e )
{
        LinkList p = L;
        int j = 0;
        while ( p && j < i - 1 ) //�ҵ���i-1��λ��
        {
                p = p->next;
                j += 1;
        }
        if ( j > i - 1 || !p )
                return ERROR; //i��λ�ò��Ϸ�ʱ,��i=0��i>Length(L)+1(����1)
        LinkList q = ( LinkList ) malloc ( sizeof ( LNode ) ); //��̬�����µĽ��
        q->data = e;   //��e��ֵ�����µĽ��
        q->next = p->next;
        p->next = q; //��i-1λ��֮������µĽ��
        return OK;
}*/

LinkedList LinkedListInsert ( LinkedList L, int i, ElemType x )
{
	LNode *pre;        //preΪǰ�����
	pre = L;
	int tempi = 0;
	for ( tempi = 1; tempi < i; tempi++ )
	{
		pre = pre->next;    //���ҵ�iλ�õ�ǰ�����
	}
	LNode *p;        //������Ϊp��
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
		
		//����û������Ƿ���1��8֮��
		int choice;
		scanf ( "%d", &choice );
		/*int choice = -1;
		int a = 1;
		printf ( "���������ѡ��" );
		while ( 1 )
		{
		        scanf ( "%d", &choice );
		        if ( choice >= 1 && choice <= 7 )
		        {
		                printf ( "\n****������Ľ����%d   ****\n", choice );
		                printf ( "\n" );
		                break;
		        }
		        else
		        {
		                fflush ( stdin ); //�������
		                printf ( "�ַ��Ƿ�������������\n" );
		        }
		}*/


		LinkedList list, start, L;
		LNode*q, *p;

		ElemType num, num1, num_index, num_insert, middle, num2;


		if ( choice == 1 ) //ok
		{

			InitList ( &list );  //��ʼ���б�


			/*�ռ����洢����*/
			puts ( "==>���������ݡ�ע�⣺ÿ����һ�����Ͱ��ո��Ȼ��������һ������ȷ��ʱ�Ͱ�enter+ctrl+z+enter" );
			list = LinkedListCreatH();
			printf ( "\n��ǰ�������Ϊ\n" );
			PrintList ( list );


		}
		else if ( choice == 2 ) //ɾ��Ԫ��
		{


			printf ( "��������Ҫɾ������\n" );
			scanf ( "%d", &num );
			DeleteList ( list, &num );
			printf ( "ɾ���ɹ�!!\n" );


		}
		else if ( choice == 3 ) //����Ԫ��
		{
			//                      printf("���������ĸ������Ԫ��\n");
			//                      scanf("%d",&num1);
			//                      printf("�����Ԫ����\n");
			//                      scanf("%d",&num_insert);
			//                      InsertList(&num1,&num_insert);
			//                      printf("\n��ǰ�������Ϊ\n");
			//                      for ( start = list->next; start != NULL; start = start->next )
			//                      {
			//                              printf ( "%d ", start->data );
			//                      }
			/*int push_data, push_i;
			printf ( "��������Ҫ�����Ԫ�غ����Ĳ���λ�ã�\n" );

			scanf ( "%d%d", &push_data, &push_i );

			Push_L ( L, push_data, push_i );
			printf ( "�������������Ϊ��\n" );
			Traverse_L ( L );*/
			int i;
			printf ( "������������ݵ�λ��\n" );
			scanf ( "%d", &i );
			printf ( "������ֵ�Բ�������\n" );
			scanf ( "%d", &num );
			LinkedListInsert ( list, i, num );

			printf ( "�µĶ�����\n" );

			PrintList ( list );

		}
		else if ( choice == 4 ) //ok
		{
			DestroyList ( &list );
			printf ( "�������ɹ�����\n" );


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
			printf ( "ż�����е�����Ľ����\n" );
			PrintList ( list );
		}

	}
}
