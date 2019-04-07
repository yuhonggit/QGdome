#include <stdio.h>
#include <stdlib.h>
#include <F:\QG训练营第二次培训\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h>


//void printfNod ( LinkStack *s )
//{
//
//	if ( s->count == 0 )
//	{
//		printf ( "链栈为空\n" );
//		return ERROR;
//	}
//	StackNode *p=*s->next;
//	while ()
//	{
//		printf ( "%d-> ", p->data );
//		p = p->next;
//	}
//	return SUCCESS;
//}
int main()
{
	while ( 1 )
	{
		printf ( "\n" );
		printf ( "\n" );
		printf ( "            	******************欢饮来到链栈de环节*************\n" );
		printf ( "	______________________________________________________________________________\n" );
		printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
		printf ( "	|----> 1: 创建栈                                                         <----|\n" );
		printf ( "	|----> 2：判断栈是不是空                                                 <----|\n" );
		printf ( "	|----> 3：入栈                                                           <----|\n" );
		printf ( "	|----> 4：出栈                                                           <----|\n" );
		printf ( "	|----> 5：检测栈的长度                                                   <----|\n" );
		printf ( "	|----> 6：清空栈                                                         <----|\n" );
		printf ( "	|----> 7：得到栈顶元素                                                   <----|\n" );
		printf ( "	|_____________________________________________________________________________|\n" );
		int choice;
		printf ( "请输入你的选择\n" );
		scanf ( "%d", &choice );
		LinkStack *list;
		int data;
		int top;
		int l;
		switch ( choice )
		{
		case 1:     // 初始化栈

			break;
		case 2:     //判断栈是不是空
			isEmptyLStack ( list );
			break;
		case 3:     //入栈
			printf ( "请输入要入栈的元素\n" );
			scanf ( "%d", &data );
			pushLStack ( list, data );

			break;
		case 4:      //出栈

			popLStack ( list );

			break;
		case 5:
			l = LStackLength ( list );
			printf ( "当前栈的长度是%d\n", l );

			break;
		case 6:
			//清空
			clearLStack ( list );
			printf ( "清空成功\n" );

			break;
		case 7:
			printf ( "当前栈顶元素是\n" );
			top = getTopLStack ( list );
			printf ( "%d", top );

			break;
//		case 8 :
//			printfNode ( list );
//			break;



		}


	}
	return 0;
}
