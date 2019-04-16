#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Book *head = NULL;//全局变量    头指针
int booknum = 0;//全局变量    书本种数


/**
 *      @name        : int viewbook()
 *      @description : view a book list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int viewbook()
{
	system ( "cls" );   //清除界面
	Book *bookpack;
	printf("\t\t当前图书状态是\n");
	for ( bookpack = head; bookpack != NULL; bookpack = bookpack->next )//一本一本书输出
	{
		printbook ( bookpack );
	}
	if ( booknum!=0 )
	{
		return booknum;
	}
	else
	{
		printf ( "\t\t图书馆还没有图书\n" );
		return ERROR;
	}
	return SUCCESS;
}

/**
 *      @name        : int addbook()
 *      @description : add a book to the list
 *      @param           : None
 *      @return          : None
 *       @notice      : None
 */
int addbook()
{

	system ( "cls" );
	char bookname[MAXNAME];//书本名字
	char authorname[MAXNAME];//著者名字
	int id, count;
	char *namep;
	while ( 1 )
	{
		id = 0;//图书id编号
		count = 0;//图书总数
		namep = NULL;//空串

		printf ( "\t\t请输入图书编号： " );
		scanf ( "%d", &id );
		getchar();
		printf ( "\t\t请输入图书名：（书名用来查找书本，请务必记住书名！！！）" );
		scanf ( "%s", bookname );
		getchar();
		printf("\t\t再次提醒您输入的书名是:《 %s 》(按enter继续)",bookname);
		getchar();
		printf ( "\t\t请输入著书人:" );
		scanf ( "%s", authorname );
		getchar();

		printf ( "\t\t请输入《%s》图书数量：", bookname );
		scanf ( "%d", &count );
		getchar();

		Book *bookpack;
		if ( ( bookpack = lookupbookname ( namep = strdup ( bookname ), id ) ) == NULL )//把bookname的字符串拷贝给namep
		{
			bookpack = ( Book * ) malloc ( sizeof ( Book ) );//每次增加书籍就开内存
			if ( bookpack == NULL || ( bookpack->book_name = namep ) == NULL )
			{
				printf ( "\t\t图书注册失败\n" );
				fflush ( stdin );//清除缓存
				continue;
			}
			bookpack->book_id = id;
			//bookpack->author_name = authorname;
			strcpy ( bookpack->author_name, authorname );//复制字符串strcpy
			bookpack->book_count = count;
			bookpack->status = 0;
			booknum++;

			bookpack->next = head;
			head = bookpack;
			printf ( "\t\t图书 《%s》 注册成功\n", bookname );
			return id;
		}
		else
		{
			fflush ( stdin );
			printf ( "\t\t图书名或编号已经被占用\n" );
		}


	}
	return SUCCESS;
}

/**
 *      @name        : int deletebook()
 *      @description : delete a book from the list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int deletebook()
{
	system ( "cls" );   //
	Book *bookpack, *fbookpack;

	int id = 0;
	printf ( "\t\t请输入要注销的图书编号：\n" );
	scanf ( "%d", &id );
	getchar();

	for ( fbookpack = bookpack = head; bookpack != NULL; fbookpack = bookpack, bookpack = bookpack->next )
	{
		if ( bookpack->book_id == id )
		{
			printbook ( bookpack );
			break;
		}
	}
	if ( bookpack != NULL )
	{
		while ( 1 )
		{
			printf ( "\t\t确定要注销此图书：Y  N " );

			char choice;
			scanf ( "%c", &choice );
			getchar();
			//检验输入
			if ( ! ( ( choice == 'Y' || choice == 'y' ) || ( choice == 'N' || choice == 'n' ) ) )
			{
				fflush ( stdin );
				printf("\t\t指令无效\n");
				continue;
			}
			if ( choice == 'Y' || choice == 'y' )
			{
				bookpack == head ? head = bookpack->next : ( fbookpack->next = bookpack->next );
				free ( bookpack->book_name );
				free(bookpack->author_name);
				free ( bookpack );
				bookpack = NULL;
				printf ( "\t\t图书注销成功\n" );
				break;
			}
			else
			{
				printf ( "\t\t放弃注销\n" );
				return 0;
			}
		}
		return id;
	}
	else
	{
		printf ( "\t\t要注销的图书编号不存在\n" );
		return ERROR;
	}
	return SUCCESS;
}


/**
 *  @name        : int modifybook()
 *      @description : mddify a book from the list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int modifybook()   // 修改除id之外的信息  因为要修改id 直接删掉后重新添加会更好
{
	system ( "cls" ); ///////////////////////////////////////////
	Book *bookpack = NULL;
	while ( 1 )
	{
		int id = 0;
		printf ( "请输入要修改信息的图书编号：\n" );
		scanf ( "%d", &id );
		getchar();
//		if ( ! ( id > 0 && id < 1000 ) )
//		{
//			fflush ( stdin );
//			//error ( "图书编号不符合要求" );
//			printf ( "\t\t\图书编号不符合要求\n" );
//			continue;
//		}
		if ( ( bookpack = lookupbookname ( "", id ) ) != NULL )
		{
			printf ( "\t\t以下为要修改的图书的现有信息：\n" );
			printbook ( bookpack );
			printf ( "\t\t【1】 修改图书名\n\t\t【2】 修改图书数量\n\t\t【3】修改著者名字\n\t\t【4】 修改图书状态\n\t\t【0】 放弃修改\n" );
			while ( 1 )
			{
				int i;
				scanf ( "%d", &i );
				getchar();
				if ( ! ( i == 1 || i == 2 || i == 3 || i == 4 || i == 0 ) )
				{
					fflush ( stdin );
					//error ( "输入项目前编号选择相关项目" );
					printf ( "\t\t请输入项目前编号选择相关项目\n" );
					continue;
				}
				switch ( i )
				{
				case 1:
					while ( 1 )
					{
						char newname[MAXNAME], *namep;
						printf ( "\t\t图书名：" );
						scanf ( "%s", newname );
						getchar();
						if ( ( lookupbookname ( namep = strdup ( newname ), 0 ) ) != NULL )
						{
							fflush ( stdin );
							printf ( "\t\t图书已经存在\n" );
							continue;
						}
						if ( ( bookpack->book_name = namep ) != NULL )
						{
							printf ( "\t\t修改成功\n" );
							return id;
						}
					}
					break;
				case 2:
					while ( 1 )
					{
						int chancenum;
						printf ( "\t\t输入图书数量：" );
						scanf ( "%d", &chancenum );
						getchar();
						bookpack->book_count = chancenum;
						printf ( "\t\t修改成功\n" );
						return id;
					}
					break;
				case 3:
//					while (1)
//					{
//						char newauthor[50],*nauthor;
//						printf("\t\t请输入著者名字\n");
//						scanf ( "%s", newauthor );
//						getchar();
//						if ( ( lookupauthorname ( nauthor = strdup ( newauthor ), 0 ) ) != NULL )
//						{
//							fflush ( stdin );
//							printf ( "\t\t已经是这个著者\n" );
//							continue;
//						}
//						if ( ( bookpack->author_name = nauthor ) != NULL )
//						{
//							printf ( "\t\t修改成功\n" );
//							return id;
//						}
//
//
//					}
					printf("\t\t著者名字无法修改\n");
					return id;
					break;
				case 4:
					while ( 1 )
					{
						char c;
						int status;
						status = bookpack->status;
						if(status==0)
						{
							printf("\t\t修改状态为“不可借”：Y（是）N（否）\n");
						}
						else
						{
							printf("\t\t修改状态为“可借”：Y（是）N（否）\n");
						}

						scanf ( "%c", &c );
						getchar();
						if ( ! ( c == 'Y' || c == 'y' || c == 'N' || c == 'n' ) )
						{
							fflush ( stdin );
							printf("\t\t指令无效\n");
							continue;
						}
						if ( c == 'Y' || c == 'y' )
						{

							if(status==0)
							{
								bookpack->status=1;
							}
							else
							{
								bookpack->status=0;
							}
							printf ( "\t\t修改成功\n" );
							return id;
						}
						else
						{
							printf ( "\t\t放弃修改\n" );
							return 0;
						}
					}
					break;
				case 0:
					return 0;
				default:

					printf ( "\t\t获取参数失败\n" );
					break;
				}
			}
		}
		else
		{
			printf ( "\t\t没有此图书\n" );
			return ERROR;
		}
	}
	return SUCCESS;
}

/**
 *      @name        : void printbook(Book *bookpack)
 *      @description : Output the corresponding attributes for each book
 *      @param           : bookpack(the bookLlist's head)
 *      @return          : None
 *      @notice      : None
 */
void printbook ( Book *bookpack )
{
	printf ( "\t\t--------------------------\n");
	printf ( "\t\t图书编号：%d\n", bookpack->book_id );
	printf ( "\t\t图书名：%s\n", bookpack->book_name );
	printf ( "\t\t著书人：%s\n", bookpack->author_name );
	printf ( "\t\t图书库存：%d\n", bookpack->book_count );
	printf("\t\t归还日期：%d\n",bookpack->returntime);
	printf ( "\t\t--------------------------\n");
	if ( bookpack->book_count != 0 )
		printf ( "\t\t---图书可借---\n" );
	else
		printf ( "\t\t---图书不可借---\n" );
}

/**
 *      @name        : Book *lookup(char *s, int id)
 *      @description :  lookup each book
 *      @param           : XXname(XX's name),id(the book's id)
 *      @return          : None
 *      @notice      : None
 */
Book *lookupbookname ( char *bookname, int id )
{
	Book *bookpack;
	for ( bookpack = head; bookpack != NULL; bookpack = bookpack->next )
	{
		if ( id == bookpack->book_id || strcmp ( bookname, bookpack->book_name ) == 0 )//strcmp比较两个字符串相等就返回0
		{
			return bookpack;
		}
	}
	return NULL;
}
Book *lookupauthorname ( char *authorname, int id )
{
	Book *bookpack;
	for ( bookpack = head; bookpack != NULL; bookpack = bookpack->next )
	{
		if ( id == bookpack->book_id || strcmp (authorname, bookpack->author_name) == 0 )
		{
			return bookpack;
		}
	}
	return NULL;
}
//Book *lookupbookid ( char *bookid, int id )
//{
//	Book *bookpack;
//	for ( bookpack = head; bookpack != NULL; bookpack = bookpack->next )
//	{
//		id == bookpack->book_id;
//		if ( id  == 0 )
//		{
//			return bookpack;
//		}
//	}
//	return NULL;
//}
/**
 *      @name        : int borrowbook()
 *      @description : borrow a book from the list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int borrowbook()
{
	system ( "cls" );
	char bookname[MAXNAME];
	printf ( "\t\t搜索图书:" );
	scanf ( "%s", bookname );
	getchar();
	Book *bookpack;
	char *namep = NULL;
	int rtime=0;
	printf("\t\t请输入你的归还日期(8月8号就写0808，10月30号写1030):");
	scanf("%d",&rtime);

	//bookpack->returntime=rtime;
	if ( ( bookpack = lookupbookname ( namep = strdup ( bookname ), 0 ) ) == NULL )
	{
		printf ( "\t\t图书 《 %s 》不存在\n", namep );
		fflush ( stdin );
		return ERROR;
	}
	else
	{
		bookpack->returntime=rtime;
		printbook ( bookpack );
		if ( ! bookpack->status )
		{
			printf ( "\t\t是否借阅图书： Y \N\n" );
		}
		else
		{
			printf ( "\t\t图书外借中\n" );
			return SUCCESS;
		}
		while ( 1 )
		{
			char c = '\0';
			scanf ( "%c", &c );
			getchar();
			if ( ! ( c == 'Y' || c == 'y' || c == 'N' || c == 'n' ) )
			{
				fflush ( stdin );
				//error ( "指令无效" );
				printf ( "\t\t指令无效" );
				continue;
			}
			if ( c == 'Y' || c == 'y' )
			{
				--bookpack->book_count > -1 ? printf ( "\t\t借阅成功(按enter键继续)\n" ) : printf ( "\t\t借阅失败(按enter键继续)\n" );
				if ( ! bookpack->book_count )
				{
					bookpack->status = 1;
				}
				return bookpack->book_id;
			}
			else
			{
				return 0;
			}
		}
	}
	return SUCCESS;
}


/**
 *  @name        : int returnbook()
 *      @description :  retur the book to the list
 *      @param           : None
 *      @return          : None
 *  @notice      : None
 */
int returnbook()
{
	system ( "cls" );
	char bookname[MAXNAME];
	printf ( "\t\t归还图书\n" );
	printf("\t\t请输入归还的图书名：");
	scanf ( "%s", bookname );
	getchar();
	Book *bookpack;
	char *namep;
	if ( ( bookpack = lookupbookname ( namep = strdup ( bookname ), 0 ) ) == NULL )
	{
		fflush ( stdin );
		printf ( "\t\t此图书并不是馆内图书\n" );
		return SUCCESS;
	}
	else
	{
		printbook ( bookpack );
		printf ( "\t\t归还图书： Y N\n" );
		while ( 1 )
		{
			char c = '\0';
			scanf ( "%c", &c );
			getchar();
			if ( ! ( c == 'Y' || c == 'y' || c == 'N' || c == 'n' ) )
			{
				fflush ( stdin );
				//error ( "指令无效" );
				printf ( "\t\t指令无效\n" );
			}
			else if ( c == 'Y' || c == 'y' )
			{
				bookpack->book_count++ ? : ( bookpack->status = 0 );
				printf ( "\t\t成功\n" );
				return bookpack->book_id;
			}
			else
			{
				return 0;
			}
		}
	}

	return SUCCESS;
}

