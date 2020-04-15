#include<iostream>
#include<malloc.h>
using namespace std;

//����ڵ�
typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

//����ջ
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
	cout<<"��ջ"<<endl;
	traversal(&stack);
	cout<<"������"<<endl;

	cout<<"-------"<<endl;
	if(pop(&stack, &val))
		cout<<"��ջ��ֵΪ��"<<val<<endl;
	if(pop(&stack, &val))
		cout<<"��ջ��ֵΪ��"<<val<<endl;
	///if(pop(&stack, &val))
		//cout<<"��ջ��ֵΪ��"<<val<<endl;
	/*if(pop(&stack, &val))
		cout<<"��ջ��ֵΪ��"<<val<<endl;
	else
		cout<<"ջΪ�գ�"<<endl;*/
	//traversal(&stack);
	clear(&stack);
	traversal(&stack);
	return 0;
}
void iniStack(PSTACK stack)
{
	//������Ҫ����һ��ͷָ�룬ʹջ��ͷ��βָ�붼ָ�����ָ��
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	pHead->pNext =NULL;
	if(pHead == NULL)
	{
		cout<<"������̬�ڴ�ʧ�ܣ�"<<endl;
		return;
	}
	stack->pTop = pHead;
	stack->pBottom = pHead;
	cout<<"������̬�ڴ�ɹ���"<<endl;
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
		cout<<"������"<<endl;
		return;
	}
	PNODE p = stack->pTop;
	while(p!= stack->pBottom) 
	{
		//Ϊʲô����p-pNext !=stack->pBottom,��Ϊ�����pNext=pBottom,��ô�൱��pBottom�ϵ�һ���ڵ��
		//����û��ȡ����ֱ��ָ����pBottom��������data�������p!=pBottom����ô�������ݵ��׵�ַ��������
		//�ڵ�ָ�����б���ĵ�ַ��
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
bool pop(PSTACK stack, int *val) //��ջһ��
{
	if(is_empty(stack))
		return false;
	PNODE p =stack->pTop;
	*val = p->data;
	stack->pTop =stack->pTop->pNext;

	free(p); //ɾ����ʱ��Ҫ�ǵ��ͷ�
	p = NULL;
	return true;
}

void clear(PSTACK stack)//ʹ��p ��q����ָ��  pָ��ͷ qָ��p����һ���ڵ�
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