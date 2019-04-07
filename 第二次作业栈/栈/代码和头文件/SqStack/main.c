#include <stdio.h>
#include <stdlib.h>
#include <F:\QG训练营第二次培训\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h>



void printfNode ( SqStack *s )
{
	printf ( "当前栈的列表是\n" );
	for ( int i = 0; i <= s ->top; i ++ ) \
	{

		printf ( "%d-> ", s ->elem[i] );
	}

}
int main()
{
	while ( 1 )
	{
		printf ( "\n" );
		printf ( "\n" );
		printf ( "            	******************欢饮来到栈de环节*************\n" );
		printf ( "	______________________________________________________________________________\n" );
		printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
		printf ( "	|----> 1: 创建栈                                                         <----|\n" );
		printf ( "	|----> 2：判断栈是不是空                                                 <----|\n" );
		printf ( "	|----> 3：入栈                                                           <----|\n" );
		printf ( "	|----> 4：出栈                                                           <----|\n" );
		printf ( "	|----> 5：检测栈的长度                                                   <----|\n" );
		printf ( "	|----> 6：清空栈                                                         <----|\n" );
		printf ( "	|----> 7：得到栈顶元素                                                   <----|\n" );
		printf ( "	|----> 8：打印栈的元素                                                   <----|\n" );
		printf ( "	|_____________________________________________________________________________|\n" );
		int choice;
		printf ( "请输入你的选择\n" );
		scanf ( "%d", &choice );
		//栈的列表
		SqStack *list;
		int top;//栈顶元素
		int size;//栈的长度
		int data;//入栈和出栈的元素
		int length;//栈的长度

		switch ( choice )
		{
		case 1:     // 初始化栈
			printf ( "请输入栈的长度\n" );
			scanf ( "%d", &size );
			initStack ( list, size );
			break;
		case 2:     //判断栈是不是空
			isEmptyStack ( list );
			break;
		case 3:     //入栈
			printf ( "请输入要入栈的元素\n" );
			scanf ( "%d", &data );
			pushStack ( list, data );

			break;
		case 4:      //出栈

			popStack ( list, data );

			break;
		case 5:
			length = stackLength ( list );
			printf ( "当前栈的长度是%d\n", length );

			break;
		case 6:
			//清空
			clearStack ( list );
			printf ( "清空成功\n" );

			break;
		case 7:
			printf("当前栈顶元素是\n");
			top=getTopStack(list);
			printf("%d",top);

		break;
		case 8 :
			printfNode ( list );
			break;



		}

	}
}
