#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct Queue
{
	int *pBase;//指向数组首地址
	int front;
	int rear;
}QUEUE, *PQUEUE;

void Ini_queue(PQUEUE Q);
void In_queue(PQUEUE Q, int val);
void traversal(PQUEUE Q);
bool is_full(PQUEUE Q);
bool is_empty(PQUEUE Q);
bool delete_queue(PQUEUE Q,int *val);

#define len 3

int main()
{
	Queue Q;
	int val;//用来保存删掉的元素；
	Ini_queue(&Q);
	traversal(&Q);
	In_queue(&Q,1);
	In_queue(&Q,2);
	traversal(&Q);
	if(delete_queue(&Q,&val))
		cout<<"被删除的数据是："<<val<<endl;
	else
		cout<<"删除失败！"<<endl;
	if(delete_queue(&Q,&val))
		cout<<"被删除的数据是："<<val<<endl;
	else
		cout<<"删除失败！"<<endl;
	if(delete_queue(&Q,&val))
		cout<<"被删除的数据是："<<val<<endl;
	else
		cout<<"删除失败！"<<endl;
	return 0;
}
void Ini_queue(PQUEUE Q)
{
	Q->pBase = new int[len];
	if(Q->pBase == NULL)
	{
		cout<<"分配内存失败！"<<endl;
		return;
	}
	else
	{
		Q->front = 0;
		Q->rear = 0;
		cout<<"分配内存成功！"<<endl;
	}
}
bool is_full(PQUEUE Q)
{
	if((Q->rear +1)%len == Q->front)//important
		return true;
	else
		return false;
}
bool is_empty(PQUEUE Q)
{
	if(Q->front == Q->rear ) //不需要==0
		return true;
	else
		return false;
}
void In_queue(PQUEUE Q, int val)
{
	//入队，把元素放在r位置上，同时r移动。
	if(is_full(Q))
	{
		cout<<"队列已满，无法入队！"<<endl;
		return;
	}
	else
	{
		Q->pBase[Q->rear] = val;
		Q->rear = (Q->rear +1)%len;
		cout<<"入队成功！"<<endl;
		return;
	}
}
void traversal(PQUEUE Q)
{
	if(is_empty(Q))
	{
		cout<<"无数据！"<<endl;
		return;
	}
	else
	{
		int i = Q->front;
		while(i != Q->rear)
		{
			cout<<Q->pBase[i]<<endl;
			i = (i + 1)%len;
		}
		return;
	}
}
bool delete_queue(PQUEUE Q,int *val)
{
	if(is_empty(Q))
		return false;
	else
	{
		*val = Q->pBase[Q->front];
		Q->front = (Q->front + 1)%len;
		return true;
	}
}