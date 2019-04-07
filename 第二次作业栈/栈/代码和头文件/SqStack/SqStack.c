#include <F:\QG训练营第二次培训\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h>
#include <stdio.h>
#include <stdlib.h>
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈  对于SqStack *s在外面是SqStack *list 传list进来
{
	s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
	if(s->elem==NULL)//判断初始的元素是不是空
		return OVERFLOW;
	s->top=-1;
	s->size=sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(s->top==-1)
	{
		printf("当前栈为空\n");
		return OVERFLOW;

	}

	else
	{
		printf("当前栈不为空\n");
		return SUCCESS;
	}

}

Status getTopStack(SqStack *s)   //得到栈顶元素  对于ElemType e在外面是int top传top进来
{
	if(s->top==-1)
		return ERROR;


	return s->elem[s->top];


}

Status clearStack(SqStack *s)   //清空栈
{
	s->top=-1;
	return SUCCESS;
}



Status destroyStack(SqStack *s) //销毁栈
{
	free(s->elem);
	s->top=-1;
}

Status stackLength(SqStack *s)   //检测栈长度
{
	 return s->top+1;
}

Status pushStack(SqStack *s,ElemType data)  //入栈  data是要入的元素
{
	if(s->top==(s->size)-1)//判断是不是满了,就是top的值是不是是长度-1
		printf("栈的满的无法入栈");
	s->top++;
	s->elem[s->top]=data;

		return SUCCESS;

}

Status popStack(SqStack *s,ElemType data)   //出栈   data是要出的元素
{
	if(s->top==-1)//判断栈是不是空的
		printf("栈是空的无法出栈");
	s->elem[s->top]=data;
	s->top--;
	return SUCCESS;
}


