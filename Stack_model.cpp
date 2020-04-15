#include<iostream>
#include<malloc.h>
using namespace std;

//定义节点
typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

//定义栈
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

void iniStack(PSTACK stack);
bool push(PSTACK stack, int value);
void traversal(PSTACK stack);
bool pop(PSTACK stack, int *val);
bool is_empty(PSTACK stack);
void clear(PSTACK stack);

int main()
{
	STACK stack;
	int val; 
	iniStack(&stack);
	cout<<"-----"<<endl;
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	cout<<"入栈"<<endl;
	traversal(&stack);
	cout<<"遍历！"<<endl;

	cout<<"-------"<<endl;
	if(pop(&stack, &val))
		cout<<"出栈的值为："<<val<<endl;
	if(pop(&stack, &val))
		cout<<"出栈的值为："<<val<<endl;
	///if(pop(&stack, &val))
		//cout<<"出栈的值为："<<val<<endl;
	/*if(pop(&stack, &val))
		cout<<"出栈的值为："<<val<<endl;
	else
		cout<<"栈为空！"<<endl;*/
	//traversal(&stack);
	clear(&stack);
	traversal(&stack);
	return 0;
}
void iniStack(PSTACK stack)
{
	//首先需要创建一个头指针，使栈的头、尾指针都指向这个指针
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	pHead->pNext =NULL;
	if(pHead == NULL)
	{
		cout<<"创建动态内存失败！"<<endl;
		return;
	}
	stack->pTop = pHead;
	stack->pBottom = pHead;
	cout<<"创建动态内存成功！"<<endl;
	return;
}
bool push(PSTACK stack, int value)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	
	pNew->pNext = stack->pTop;
	stack->pTop = pNew;
	pNew->data = value;
	return true;
}
void traversal(PSTACK stack)
{
	if(stack->pTop ==stack->pBottom)
	{
		cout<<"无数据"<<endl;
		return;
	}
	PNODE p = stack->pTop;
	while(p!= stack->pBottom) 
	{
		//为什么不是p-pNext !=stack->pBottom,因为如果是pNext=pBottom,那么相当于pBottom上的一个节点的
		//数据没有取出。直接指向了pBottom，跳过了data。如果是p!=pBottom，那么则是数据的首地址，而不是
		//节点指针域中保存的地址。
		cout<<p->data<<endl;
		p = p->pNext;
	}
	return;
}
bool is_empty(PSTACK stack)
{
	if(stack->pTop ==stack->pBottom)
		return true;
	else
		return false;
}
bool pop(PSTACK stack, int *val) //出栈一次
{
	if(is_empty(stack))
		return false;
	PNODE p =stack->pTop;
	*val = p->data;
	stack->pTop =stack->pTop->pNext;

	free(p); //删除的时候要记得释放
	p = NULL;
	return true;
}

void clear(PSTACK stack)//使用p 和q两个指针  p指向头 q指向p的下一个节点
{
	if(is_empty(stack))
		return;
	else
	{
		PNODE p = stack->pTop;
		PNODE q = NULL;
		while(p != stack->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		stack->pTop = stack->pBottom;
	}
}