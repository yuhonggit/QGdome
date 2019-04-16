#include <stdio.h>
#include <stdlib.h>
#include <AQueue.h>
#include <string.h>


//初始化结点
Type ORI = {.type = 0};

//将x转化为小数点后面的值
double divnum(int x)
{
	double ret = x;
	//保证精度
	while((ret+0.00001) >= 1)
		ret/=10;
	return ret;
}
//返回指向类型的不确定类型指针
void* readin(Type *temp)
{
	*temp = ORI;
	void *p;
	p = temp;
	//标记是否成功读取输入
	int flag = 0;

	//读入用户输入
	char ch;
	char s[MAX_STRINGS_LENGTH];
	int len = 0;
	while((ch = getchar()) && ch != '\n')
		s[len++] = ch;
	s[len] = '\0';

	//处理用户输入
	int i = 0;
	while(s[i]!='\0')
	{
		if(s[i] == ' ')continue;
		if(s[i] == '\'')//字符类型
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
					//两个及以上字符
					flag = 0;
					break;
				}
			}
		}
		else if(s[i] == '\"')//字符串类型
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
		else if(s[i] >= '0' && s[i] <= '9')//常数类型
		{
			int ans = 0;
			int flag1 = 0;//浮点数标记
			while(s[i] != '\0')
			{
				if(s[i] == '.')
				{
					//两个及以上小数点
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
			//如果输入的是浮点数
			if(flag1 && flag)
			{
				temp->real_number += divnum(ans);
				temp->type = 2;
			}
			//输入的是整数
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
		printf ( "            	*****************欢饮来队列de环节***************\n" );
		printf ( "	______________________________________________________________________________\n" );
		printf ( "	|---->           Please enter the selection you want to operate on       <----|\n" );
		printf ( "	|----> 1: Creat the queue                                                <----|\n" );
		printf ( "	|----> 2：Insert queue                                                   <----|\n" );
		printf ( "	|----> 3：Remove queue                                                   <----|\n" );
		printf ( "	|----> 4：Destory queue                                                  <----|\n" );
		printf ( "	|----> 5：Empty queue                                                    <----|\n" );
		printf ( "	|----> 6：Get the queue's length                                         <----|\n" );
		printf ( "	|----> 7：Get the top element                                            <----|\n" );
		printf ( "	|----> 8：Output queue                                                   <----|\n" );
		printf ( "	|----> 9：Determine the queue is empty                                   <----|\n" );
		printf ( "	|----> 10：Determine the queue is full                                   <----|\n" );
		printf ( "	|_____________________________________________________________________________|\n" );
		int choice;
		printf ( "请输入你的选择\n" );
		scanf ( "%d", &choice );
		AQueue *list;//队列列表
		int length;//队列长度

		//要插入的元素
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
		case 1://初始化（完）
		{
			InitAQueue ( list );

			printf ( "初始化成功\n" );
			break;
		}

		case 2://入队
		{


			printf ( "整型和浮点型为标准输入即可，若是字符型请加'' (请不要输错)\n" );
			printf ( "请输入需要入队的元素:" );
			Type *temp = ( Type * ) malloc ( sizeof ( Type ) );
			void *p = readin ( temp );
			EnAQueue(list,p);

			break;
			//                      printf ( "选择你要输入的数字类型\n" );
			//                      printf ( "1.整型\t2.浮点型\t3.字符串型\n" );
			//                      scanf ( "%d", &select );
			//                      if ( select == 1 )
			//                      {
			//                              printf ( "你要入的元素是\n" );
			//                              scanf ( "%d", &a );
			//                              EnAQueue ( list, &a );
			//
			//                      }
			//                      else if ( select == 2 )
			//                      {
			//                              printf ( "你要入的元素是\n" );
			//                            scanf ( "%lf", &b );
			//                              EnAQueue ( list, &b );
			//
			//                      }
			/*else if ( select == 3 )
			{
			        printf ( "你要入的元素是\n" );
			        scanf ( "%s", &cb );
			        EnAQueue ( list, &cb );
			}*/
			//                      length = LengthAQueue ( list ); //检测长度
			//                      printf ( "当前队列的长度是：%d\n", length );
			//                      printf ( "当前队列是\n" );
			//                      TraverseAQueue ( list, APrint );

		}

		case 3://出队(完)
		{
			DeAQueue ( list );
			length = LengthAQueue ( list ); //检测长度
			printf ( "\n当前队列的长度是：%d\n", length );
			break;
		}

		case 4://销毁队列(完)
		{
			DestoryAQueue ( list );
			printf ( "删除成功\n" );

			break;
		}

		case 5://清空队列（完）
		{
			ClearAQueue ( list );
			break;
		}

		case 6://得到队列长度（完）
		{
			length = LengthAQueue ( list );
			printf ( "队列长度是 %d\n", length );
			break;
		}

		case 7://得到队列头元素
		{
			Type *temp = ( Type * ) malloc ( sizeof ( Type ) );

			//判断是不是空再打印
			if ( GetHeadAQueue ( list, temp ) == 1 )
			{
				printf ( "队列头元素是\n" );
				APrint_top( temp );
			}

			break;
		}
		case 8://遍历输出队列
		{
			//TraverseAQueue(list,APrint());
			printf ( "当前队列是\n" );
			TraverseAQueue ( list, APrint );
			break;
		}

		case 9://判断队列是不是空的（完）
		{
			IsEmptyAQueue ( list );//会提示成功
			break;
		}

		case 10://判断队列是不是满的（完）
		{
			IsFullAQueue ( list );
			break;
		}



		}

	}

}
