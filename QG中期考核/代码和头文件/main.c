#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "book.h"

//身份选择界面初始化
int idnumber;
int id_init()
{
	int choice, confirm;
	printf (

	        "\n\t\t_______________________________________________________\t\n"
	        "\t\t|【1】:\t管理员                                         |\t\n"
	        "\t\t|【2】:\t借书者                                         |\t\n"
	        "\t\t|【3】:\t退出                                           |\t\n"
	        "\t\t|______________________________________________________|\t\n\n"
	);
	printf ( "\t\t请输入您的选择：" );
	scanf ( " %d", &choice );
	while ( ( confirm = getchar() ) != '\n' ) //用户再次输入空格键才表示其真正确认
		continue;
	//输入检测
	while ( choice != 3 && ( choice < 1 || choice > 2 ) ) //判断执行1-2，并且检测合法输入
	{
		printf ( "\t\t您的输入: '%d' 有误!请重新输入：", choice );
		scanf ( " %d", &choice );

	}
	return choice;
}
/*管理者界面*/
int usermanger()
{

	int manger_choice;
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t请输入项目前编号执行相关操作：\n\n" );
	printf ( "\t\t【1】 查看已存图书\n" );
	printf ( "\t\t【2】 注册新图书\n" );
	printf ( "\t\t【3】 修改已有图书信息\n" );
	printf ( "\t\t【4】 注销现存图书\n" );
	printf ( "\t\t【0】 返回主页\n" );
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t输入您的选择:" );
	scanf ( "%d", &manger_choice );
	while ( manger_choice != 0 && ( manger_choice < 1 || manger_choice > 4 ) )
	{
		printf ( "\t\t您输入的：'%d' 有误！请重新输入：", manger_choice );
		scanf ( "%d", &manger_choice );
	}
	return manger_choice;
	//      switch ( manger_choice )
	//      {
	//      case 0:
	//
	//              return 0;
	//      case 1:
	//              printf("\t\t查看已存图书\n");
	//              break;
	//      case 2:
	//              printf("\t\t注册新图书\n");
	//              break;
	//      case 3:
	//              printf("\t\t修改已有的图书信息\n");
	//              break;
	//      case 4:
	//              printf("\t\t注销现存图书\n");
	//              break;
	//
	//      }

}
/*借书者界面*/
int userborrower()
{
	int borrower_choice;
	getchar();
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t请输入你要执行的操作\n" );
	printf ( "\t\t【1】查看已存图书\n" );
	printf ( "\t\t【2】借阅图书\n" );
	printf ( "\t\t【3】归还图书\n" );
	printf ( "\t\t【0】返回主页\n" );
	printf ( "\t\t-------------------------------------\n" );
	printf ( "\t\t请输入你的选择:" );
	scanf ( "%d", &borrower_choice );
	while ( borrower_choice != 0 && ( borrower_choice < 1 || borrower_choice > 3 ) )
	{
		printf ( "\t\t您输入的：'%d' 有误！请重新输入：", borrower_choice );
		scanf ( "%d", &borrower_choice );
	}
	return borrower_choice;
	//      switch ( borrower_choice )
	//      {
	//      case 0:
	//              return 0;
	//      case 1:
	//              printf("\t\t查看已存图书\n");
	//              break;
	//      case 2:
	//              printf("\t\t查看已存图书\n");
	//              break;
	//      case 3:
	//              printf("\t\t查看已存图书\n");
	//              break;
	//
	//      }
}

int main()
{
	printf ( "\t\t\t\t\t\t\t\t『制作：宏   时间：2019年4月10日   名称：图书管理系统』\n\n" );
	printf ( "\t\t*****************欢迎来到图书管理系统*******************\n" );
	int choice;
	int borrower_choice;
	int manger_choice;
	//选择身份
	while ( ( choice = id_init() ) && choice != 3 )
	{
		system ( "cls" );
		switch ( choice )
		{
		case 1:
			printf ( "\t\t你是管理员\n" );

			while ( ( manger_choice = usermanger() ) && manger_choice != 0 )
			{
				switch ( manger_choice )
				{
				case 1:
					//printf ( "\t\t查看已存图书\n" );
					viewbook();
					break;
				case 2:
					//printf ( "\t\t输入图书\n" );
					addbook();
					break;
				case 3:
					//printf ( "\t\t修改已有图书信息\n" );
					modifybook();
					break;
				case 4:
					//printf ( "\t\t注销现存图书\n" );
					deletebook();
					break;

				}

			}
			//system ( "cls" );
			break;
		case 2:
			printf ( "\t\t你是借书者\n" );
			printf ( "\t\t请输入你的借书证号:" );
			scanf ( "%d", &idnumber );
			while ( ( borrower_choice = userborrower() ) && borrower_choice != 0 )
			{
				switch ( borrower_choice )
				{
				case 1:
					//printf ( "\t\t查看已存图书\n" );
					viewbook();
					break;
				case 2:
					//printf ( "\t\t借阅图书\n" );
					borrowbook();

					break;
				case 3:
					//printf ( "\t\t归还图书\n" );
					returnbook();

					break;
				}

			}
			idnumber = 0;
			//system ( "cls" );

			break;

		}
	}
	printf ( "\t\t您已退出图书管理系统，感谢您的使用!\n" );
	system ( "pause" );

}
