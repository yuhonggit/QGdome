#include <stdio.h>
#include <stdlib.h>
#include <F:\QG训练营第二次培训\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h>

//链栈(基于链表的)
//StackNode是结构体变量    LinkStackPtr是一级指针
Status initLStack ( LinkStack *s ) //初始化   在主函数外声明LinkStack *list 传list进来
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}



Status isEmptyLStack ( LinkStack *s ) //判断链栈是否为空
{
	if ( s->top == NULL )
	{
		printf ( "链栈为空\n" );
		return ERROR;
	}
	else
	{
		printf ( "链栈不为空\n" );
		return SUCCESS;
	}
}


Status getTopLStack ( LinkStack *s ) //得到栈顶元素,ElemType *e 到时候传&list进来然后就
{
	if ( s->top == NULL )
	{
		printf ( "栈为空\n" );
		return ERROR;

	}
	return s->top->data;//栈头头指针指向的头数据



}

Status clearLStack ( LinkStack *s ) //清空栈
{
	s->top == NULL;
}

Status destroyLStack ( LinkStack *s ) //销毁栈
{
	free ( s );
}

Status LStackLength ( LinkStack *s ) //检测栈长度, int *length
{
//	StackNode* p = s;
//	int length = 0;
//	while ( p->next != NULL )
//	{
//		p = p->next;
//		length++;
//	}
//	return length;
	return s->count;
}
Status pushLStack ( LinkStack *s, ElemType data ) //入栈
{
	StackNode *p;
	p = ( StackNode * ) malloc ( sizeof ( StackNode ) );
	if ( p == NULL )
	{
		return ERROR;
	}
	//s是原来，p是新加的
	p->data = data;//data传入新来的数据域即新来的p的data
	p->next = s->top;//p的next指针等于原来的top指针
	s->top = p;
	s->count++;

	return SUCCESS;
}

Status popLStack ( LinkStack *s ) //出栈
{

	int e;
	if ( NULL == s->top )
	{
		return ERROR;
	}
	StackNode *p;
	p = s->top;//P指向栈顶结点
	e = p->data;
	s->top = p->next;//栈顶指针下移一位
	free ( p );//释放p
	s->count--;

	return e;
}
