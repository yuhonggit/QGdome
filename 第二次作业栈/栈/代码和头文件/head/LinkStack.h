#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode{
	ElemType data;//������
	struct StackNode *next;//ָ����
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{//LinkStack *s����ָ��LinkStack�Ķ���ָ�룬Ҳ��ָ��StackNode�Ķ���ָ��
	LinkStackPtr top;//ջ��ָ�룬���top����ָָ��LinkStack��һ��ָ��
	int	count;//ջ��Ԫ�صĸ���
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s);//�õ�ջ��Ԫ��,ElemType *e
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s);//���ջ����,int *length
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s);//��ջ


#endif // STACK_H_INCLUDED
