#include <stdio.h>
#include <stdlib.h>
#include <AQueue.h>
#include <string.h>


//��ʼ�����
Type ORI = {.type = 0};

//��xת��ΪС��������ֵ
double divnum(int x)
{
	double ret = x;
	//��֤����
	while((ret+0.00001) >= 1)
		ret/=10;
	return ret;
}
//����ָ�����͵Ĳ�ȷ������ָ��
void* readin(Type *temp)
{
	*temp = ORI;
	void *p;
	p = temp;
	//����Ƿ�ɹ���ȡ����
	int flag = 0;

	//�����û�����
	char ch;
	char s[MAX_STRINGS_LENGTH];
	int len = 0;
	while((ch = getchar()) && ch != '\n')
		s[len++] = ch;
	s[len] = '\0';

	//�����û�����
	int i = 0;
	while(s[i]!='\0')
	{
		if(s[i] == ' ')continue;
		if(s[i] == '\'')//�ַ�����
		{
			i++;
			while(s[i] != '\'' && s[i] != '\0')
			{
				if(!flag)
				{
					flag = 1;
					temp->type = 3;
					temp->character = s[i];
					i++;
				}
				else
				{
					//�����������ַ�
					flag = 0;
					break;
				}
			}
		}
		else if(s[i] == '\"')//�ַ�������
		{
			i++;
			int left = i;
			while(s[i] != '\"' && s[i] != '\0')
				i++;
//			if(s[i] == '\"')
//			{
//				strncpy(temp->strings,s+left,i-left);
//				temp->strings[i-left] = '\0';
//				temp->type = 4;
//				flag = 1;
//			}
		}
		else if(s[i] >= '0' && s[i] <= '9')//��������
		{
			int ans = 0;
			int flag1 = 0;//���������
			while(s[i] != '\0')
			{
				if(s[i] == '.')
				{
					//����������С����
					if(flag1)
					{
						flag = 0;
						break;
					}
					temp->real_number = ans;
					ans = 0;
					flag1 = 1;
					i++;
					continue;
				}
				ans = ans*10 + s[i]-'0';
				i++;
				flag = 1;
			}
			//���������Ǹ�����
			if(flag1 && flag)
			{
				temp->real_number += divnum(ans);
				temp->type = 2;
			}
			//�����������
			else if(flag)
			{
				temp->integer = ans;
				temp->type = 1;
			}
		}
		break;
	}
	if(flag)return p;
	else
	{

		return readin(temp);
	}

}

int main()
{
	//AQueue list;
	while ( 1 )
	{
		printf ( "\n" );
		printf ( "\n" );
		printf ( "            	*****************����������de����***************\n" );
		printf ( "	______________________________________________________________________________\n" );
		printf ( "	|---->           Please enter the selection you want to operate on       <----|\n" );
		printf ( "	|----> 1: Creat the queue                                                <----|\n" );
		printf ( "	|----> 2��Insert queue                                                   <----|\n" );
		printf ( "	|----> 3��Remove queue                                                   <----|\n" );
		printf ( "	|----> 4��Destory queue                                                  <----|\n" );
		printf ( "	|----> 5��Empty queue                                                    <----|\n" );
		printf ( "	|----> 6��Get the queue's length                                         <----|\n" );
		printf ( "	|----> 7��Get the top element                                            <----|\n" );
		printf ( "	|----> 8��Output queue                                                   <----|\n" );
		printf ( "	|----> 9��Determine the queue is empty                                   <----|\n" );
		printf ( "	|----> 10��Determine the queue is full                                   <----|\n" );
		printf ( "	|_____________________________________________________________________________|\n" );
		int choice;
		printf ( "���������ѡ��\n" );
		scanf ( "%d", &choice );
		AQueue *list;//�����б�
		int length;//���г���

		//Ҫ�����Ԫ��
		//int select;
		//              struct DATA *data_ni;
		//              data_ni=&type;
		//              int select;
		//              int a;
		//              double b;
		//              char c;
		//              int select;
		//              int a;
		//              char cb[10];
		//              char c;
		//              double b;
		switch ( choice )
		{
		case 1://��ʼ�����꣩
		{
			InitAQueue ( list );

			printf ( "��ʼ���ɹ�\n" );
			break;
		}

		case 2://���
		{


			printf ( "���ͺ͸�����Ϊ��׼���뼴�ɣ������ַ������'' (�벻Ҫ���)\n" );
			printf ( "��������Ҫ��ӵ�Ԫ��:" );
			Type *temp = ( Type * ) malloc ( sizeof ( Type ) );
			void *p = readin ( temp );
			EnAQueue(list,p);

			break;
			//                      printf ( "ѡ����Ҫ�������������\n" );
			//                      printf ( "1.����\t2.������\t3.�ַ�����\n" );
			//                      scanf ( "%d", &select );
			//                      if ( select == 1 )
			//                      {
			//                              printf ( "��Ҫ���Ԫ����\n" );
			//                              scanf ( "%d", &a );
			//                              EnAQueue ( list, &a );
			//
			//                      }
			//                      else if ( select == 2 )
			//                      {
			//                              printf ( "��Ҫ���Ԫ����\n" );
			//                            scanf ( "%lf", &b );
			//                              EnAQueue ( list, &b );
			//
			//                      }
			/*else if ( select == 3 )
			{
			        printf ( "��Ҫ���Ԫ����\n" );
			        scanf ( "%s", &cb );
			        EnAQueue ( list, &cb );
			}*/
			//                      length = LengthAQueue ( list ); //��ⳤ��
			//                      printf ( "��ǰ���еĳ����ǣ�%d\n", length );
			//                      printf ( "��ǰ������\n" );
			//                      TraverseAQueue ( list, APrint );

		}

		case 3://����(��)
		{
			DeAQueue ( list );
			length = LengthAQueue ( list ); //��ⳤ��
			printf ( "\n��ǰ���еĳ����ǣ�%d\n", length );
			break;
		}

		case 4://���ٶ���(��)
		{
			DestoryAQueue ( list );
			printf ( "ɾ���ɹ�\n" );

			break;
		}

		case 5://��ն��У��꣩
		{
			ClearAQueue ( list );
			break;
		}

		case 6://�õ����г��ȣ��꣩
		{
			length = LengthAQueue ( list );
			printf ( "���г����� %d\n", length );
			break;
		}

		case 7://�õ�����ͷԪ��
		{
			Type *temp = ( Type * ) malloc ( sizeof ( Type ) );

			//�ж��ǲ��ǿ��ٴ�ӡ
			if ( GetHeadAQueue ( list, temp ) == 1 )
			{
				printf ( "����ͷԪ����\n" );
				APrint_top( temp );
			}

			break;
		}
		case 8://�����������
		{
			//TraverseAQueue(list,APrint());
			printf ( "��ǰ������\n" );
			TraverseAQueue ( list, APrint );
			break;
		}

		case 9://�ж϶����ǲ��ǿյģ��꣩
		{
			IsEmptyAQueue ( list );//����ʾ�ɹ�
			break;
		}

		case 10://�ж϶����ǲ������ģ��꣩
		{
			IsFullAQueue ( list );
			break;
		}



		}

	}

}
