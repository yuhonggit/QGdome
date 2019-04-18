/***************************************************************************************
 *	File Name				:   book.h
 *	CopyRight				:   2019 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:   2019.4.13
 *	Author/Corportation		        :   honnggit
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data		Revised By		Item		Description
 *
 *
 ***************************************************************************************/
#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#define SUCCESS 0
#define ERROR 1

#define MAXNAME 50
#define MAXAUTHORNAME 100

typedef struct book
{
	int book_id;//书本编号
	char *book_name;//书本名字
	char author_name[MAXAUTHORNAME];//著者姓名
	int book_count;//书的数量
	int status;//书的状态
	int returntime;//归还时间
	struct book*next;//结构体指针指向下一个数据的数据域
}Book;

/*manger operation*/

/**
 *      @name        : int viewbook()
 *      @description : view a book list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int viewbook();

/**
 *      @name        : int addbook()
 *      @description : add a book to the list
 *      @param           : None
 *      @return          : None
 *       @notice      : None
 */
int addbook();

/**
 *      @name        : int deletebook()
 *      @description : delete a book from the list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int deletebook();

/**
 *  @name        : int modifybook()
 *      @description : mddify a book from the list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int modifybook();

/**
 *      @name        : void printbook(Book *bookpack)
 *      @description : Output the corresponding attributes for each book
 *      @param           : bookpack(the bookLlist's head)
 *      @return          : None
 *      @notice      : None
 */
void printbook(Book *bookpack);

/**
 *      @name        : Book *lookup(char *s, int id)
 *      @description :  lookup each book
 *      @param           : XXname(XX's name),id(the book's id)
 *      @return          : None
 *      @notice      : None
 */
Book *lookupbookname ( char *bookname, int id );
Book *lookupauthorname ( char *authorname, int id );

/**
 *      @name        : int borrowbook()
 *      @description : borrow a book from the list
 *      @param           : None
 *      @return          : None
 *      @notice      : None
 */
int borrowbook();

/**
 *  @name        : int returnbook()
 *      @description :  retur the book to the list
 *      @param           : None
 *      @return          : None
 *  @notice      : None
 */
int returnbook();




#endif //BOOK_H_INCLUDED
