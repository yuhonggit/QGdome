#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#define OVERFLOW -1
typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
	ElemType *elem;//����Ԫ���൱�������ͷָ��
	int top;//����ջ��ָ�룬ָ��������±�
	int size;//ջ�����ռ�
} SqStack;


//˳��ջ(���������)
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s);//���ջ����
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s,ElemType data);//��ջ


#endif // STACK_H_INCLUDED
