#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "book.h"

//���ѡ������ʼ��
int idnumber;
int id_init()
{
	int choice, confirm;
	printf (

	        "\n\t\t_______________________________________________________\t\n"
	        "\t\t|��1��:\t����Ա                                         |\t\n"
	        "\t\t|��2��:\t������                                         |\t\n"
	        "\t\t|��3��:\t�˳�                                           |\t\n"
	        "\t\t|______________________________________________________|\t\n\n"
	);
	printf ( "\t\t����������ѡ��" );
	scanf ( " %d", &choice );
	while ( ( confirm = getchar() ) != '\n' ) //�û��ٴ�����ո���ű�ʾ������ȷ��
		continue;
	//������
	while ( choice != 3 && ( choice < 1 || choice > 2 ) ) //�ж�ִ��1-2�����Ҽ��Ϸ�����
	{
		printf ( "\t\t��������: '%d' ����!���������룺", choice );
		scanf ( " %d", &choice );

	}
	return choice;
}
/*�����߽���*/
int usermanger()
{

	int manger_choice;
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t��������Ŀǰ���ִ����ز�����\n\n" );
	printf ( "\t\t��1�� �鿴�Ѵ�ͼ��\n" );
	printf ( "\t\t��2�� ע����ͼ��\n" );
	printf ( "\t\t��3�� �޸�����ͼ����Ϣ\n" );
	printf ( "\t\t��4�� ע���ִ�ͼ��\n" );
	printf ( "\t\t��0�� ������ҳ\n" );
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t��������ѡ��:" );
	scanf ( "%d", &manger_choice );
	while ( manger_choice != 0 && ( manger_choice < 1 || manger_choice > 4 ) )
	{
		printf ( "\t\t������ģ�'%d' �������������룺", manger_choice );
		scanf ( "%d", &manger_choice );
	}
	return manger_choice;
	//      switch ( manger_choice )
	//      {
	//      case 0:
	//
	//              return 0;
	//      case 1:
	//              printf("\t\t�鿴�Ѵ�ͼ��\n");
	//              break;
	//      case 2:
	//              printf("\t\tע����ͼ��\n");
	//              break;
	//      case 3:
	//              printf("\t\t�޸����е�ͼ����Ϣ\n");
	//              break;
	//      case 4:
	//              printf("\t\tע���ִ�ͼ��\n");
	//              break;
	//
	//      }

}
/*�����߽���*/
int userborrower()
{
	int borrower_choice;
	getchar();
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t��������Ҫִ�еĲ���\n" );
	printf ( "\t\t��1���鿴�Ѵ�ͼ��\n" );
	printf ( "\t\t��2������ͼ��\n" );
	printf ( "\t\t��3���黹ͼ��\n" );
	printf ( "\t\t��0��������ҳ\n" );
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t���������ѡ��:" );
	scanf ( "%d", &borrower_choice );
	while ( borrower_choice != 0 && ( borrower_choice < 1 || borrower_choice > 3 ) )
	{
		printf ( "\t\t������ģ�'%d' �������������룺", borrower_choice );
		scanf ( "%d", &borrower_choice );
	}
	return borrower_choice;
	//      switch ( borrower_choice )
	//      {
	//      case 0:
	//              return 0;
	//      case 1:
	//              printf("\t\t�鿴�Ѵ�ͼ��\n");
	//              break;
	//      case 2:
	//              printf("\t\t�鿴�Ѵ�ͼ��\n");
	//              break;
	//      case 3:
	//              printf("\t\t�鿴�Ѵ�ͼ��\n");
	//              break;
	//
	//      }
}

int main()
{
	printf ( "\t\t\t\t\t\t\t\t����������   ʱ�䣺2019��4��10��   ���ƣ�ͼ�����ϵͳ��\n\n" );
	printf ( "\t\t*****************��ӭ����ͼ�����ϵͳ*******************\n" );
	int choice;
	int borrower_choice;
	int manger_choice;
	//ѡ�����
	while ( ( choice = id_init() ) && choice != 3 )
	{
		system ( "cls" );
		switch ( choice )
		{
		case 1:
			printf ( "\t\t���ǹ���Ա\n" );

			while ( ( manger_choice = usermanger() ) && manger_choice != 0 )
			{
				switch ( manger_choice )
				{
				case 1:
					//printf ( "\t\t�鿴�Ѵ�ͼ��\n" );
					viewbook();
					break;
				case 2:
					//printf ( "\t\t����ͼ��\n" );
					addbook();
					break;
				case 3:
					//printf ( "\t\t�޸�����ͼ����Ϣ\n" );
					modifybook();
					break;
				case 4:
					//printf ( "\t\tע���ִ�ͼ��\n" );
					deletebook();
					break;

				}

			}
			//system ( "cls" );
			break;
		case 2:
			printf ( "\t\t���ǽ�����\n" );
			printf ( "\t\t��������Ľ���֤��:" );
			scanf ( "%d", &idnumber );
			while ( ( borrower_choice = userborrower() ) && borrower_choice != 0 )
			{
				switch ( borrower_choice )
				{
				case 1:
					//printf ( "\t\t�鿴�Ѵ�ͼ��\n" );
					viewbook();
					break;
				case 2:
					//printf ( "\t\t����ͼ��\n" );
					borrowbook();

					break;
				case 3:
					//printf ( "\t\t�黹ͼ��\n" );
					returnbook();

					break;
				}

			}
			idnumber = 0;
			//system ( "cls" );

			break;

		}
	}
	printf ( "\t\t�����˳�ͼ�����ϵͳ����л����ʹ��!\n" );
	system ( "pause" );

}
