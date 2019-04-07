#include <F:\QGѵ��Ӫ�ڶ�����ѵ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h>
#include <stdio.h>
#include <stdlib.h>
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ  ����SqStack *s��������SqStack *list ��list����
{
	s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
	if(s->elem==NULL)//�жϳ�ʼ��Ԫ���ǲ��ǿ�
		return OVERFLOW;
	s->top=-1;
	s->size=sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1)
	{
		printf("��ǰջΪ��\n");
		return OVERFLOW;

	}

	else
	{
		printf("��ǰջ��Ϊ��\n");
		return SUCCESS;
	}

}

Status getTopStack(SqStack *s)   //�õ�ջ��Ԫ��  ����ElemType e��������int top��top����
{
	if(s->top==-1)
		return ERROR;


	return s->elem[s->top];


}

Status clearStack(SqStack *s)   //���ջ
{
	s->top=-1;
	return SUCCESS;
}



Status destroyStack(SqStack *s) //����ջ
{
	free(s->elem);
	s->top=-1;
}

Status stackLength(SqStack *s)   //���ջ����
{
	 return s->top+1;
}

Status pushStack(SqStack *s,ElemType data)  //��ջ  data��Ҫ���Ԫ��
{
	if(s->top==(s->size)-1)//�ж��ǲ�������,����top��ֵ�ǲ����ǳ���-1
		printf("ջ�������޷���ջ");
	s->top++;
	s->elem[s->top]=data;

		return SUCCESS;

}

Status popStack(SqStack *s,ElemType data)   //��ջ   data��Ҫ����Ԫ��
{
	if(s->top==-1)//�ж�ջ�ǲ��ǿյ�
		printf("ջ�ǿյ��޷���ջ");
	s->elem[s->top]=data;
	s->top--;
	return SUCCESS;
}


