#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#define OVERFLOW -1
typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
	ElemType *elem;//储存元素相当于数组的头指针
	int top;//用于栈顶指针，指向的数组下标
	int size;//栈的最大空间
} SqStack;


//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s);//检测栈长度
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s,ElemType data);//出栈


#endif // STACK_H_INCLUDED
