#include <stdio.h>
#include <stdlib.h>
#include <F:\QGѵ��Ӫ�ڶ�����ѵ\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h>

//��ջ(���������)
//StackNode�ǽṹ�����    LinkStackPtr��һ��ָ��
Status initLStack ( LinkStack *s ) //��ʼ��   ��������������LinkStack *list ��list����
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}



Status isEmptyLStack ( LinkStack *s ) //�ж���ջ�Ƿ�Ϊ��
{
	if ( s->top == NULL )
	{
		printf ( "��ջΪ��\n" );
		return ERROR;
	}
	else
	{
		printf ( "��ջ��Ϊ��\n" );
		return SUCCESS;
	}
}


Status getTopLStack ( LinkStack *s ) //�õ�ջ��Ԫ��,ElemType *e ��ʱ��&list����Ȼ���
{
	if ( s->top == NULL )
	{
		printf ( "ջΪ��\n" );
		return ERROR;

	}
	return s->top->data;//ջͷͷָ��ָ���ͷ����



}

Status clearLStack ( LinkStack *s ) //���ջ
{
	s->top == NULL;
}

Status destroyLStack ( LinkStack *s ) //����ջ
{
	free ( s );
}

Status LStackLength ( LinkStack *s ) //���ջ����, int *length
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
Status pushLStack ( LinkStack *s, ElemType data ) //��ջ
{
	StackNode *p;
	p = ( StackNode * ) malloc ( sizeof ( StackNode ) );
	if ( p == NULL )
	{
		return ERROR;
	}
	//s��ԭ����p���¼ӵ�
	p->data = data;//data����������������������p��data
	p->next = s->top;//p��nextָ�����ԭ����topָ��
	s->top = p;
	s->count++;

	return SUCCESS;
}

Status popLStack ( LinkStack *s ) //��ջ
{

	int e;
	if ( NULL == s->top )
	{
		return ERROR;
	}
	StackNode *p;
	p = s->top;//Pָ��ջ�����
	e = p->data;
	s->top = p->next;//ջ��ָ������һλ
	free ( p );//�ͷ�p
	s->count--;

	return e;
}
