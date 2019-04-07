#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode{
	ElemType data;//数据域
	struct StackNode *next;//指针域
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{//LinkStack *s就是指向LinkStack的二级指针，也是指向StackNode的二级指针
	LinkStackPtr top;//栈顶指针，这个top就是指指向LinkStack的一级指针
	int	count;//栈中元素的个数
}LinkStack;



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s);//得到栈顶元素,ElemType *e
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s);//检测栈长度,int *length
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s);//出栈


#endif // STACK_H_INCLUDED
