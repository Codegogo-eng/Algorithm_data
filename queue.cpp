#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

typedef struct Queue
{
	PNODE front;
	PNODE rear;
}QUEUE, *PQUEUE;

void ini_Queue(PQUEUE);
void push_Queue(PQUEUE, int);
void traversal(PQUEUE queue);
bool is_empty(PQUEUE queue);
void delete_Queue(PQUEUE queue);
void Out_Queue(PQUEUE queue, int *val);
void clear(PQUEUE queue);

int main()
{
	QUEUE queue;
	int val;
	ini_Queue(&queue);
	push_Queue(&queue, 3);
	push_Queue(&queue, 4);
	push_Queue(&queue, 4);
	traversal(&queue);
	cout<<"--------"<<endl;
	delete_Queue(&queue);
	traversal(&queue);
	cout<<"---------"<<endl;
	Out_Queue(&queue, &val);
	cout<<"出队的值为："<<val<<endl;
	traversal(&queue);
	//Out_Queue(&queue, &val);
	//cout<<"出队的值为："<<val<<endl;
	//traversal(&queue);
	cout<<"---------"<<endl;
	clear(&queue);
	traversal(&queue);
	return 0;
}
void ini_Queue(PQUEUE queue)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	pHead->pNext =NULL; //赋为空值 这一步很重要。
	if(pHead == NULL)
	{
		cout<<"分配内存失败！"<<endl;
		return;
	}
	else
	{
		queue->front = pHead;
		queue->rear = pHead;
		cout<<"队列初始化成功！"<<endl;
		return;
	}
}
void push_Queue(PQUEUE queue, int val)
{
	//创建新节点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext =NULL;
	queue->rear->pNext = pNew;
	queue->rear = pNew;
}
void traversal(PQUEUE queue)
{
	if(is_empty(queue))
	{
		cout<<"无数据！"<<endl;
		return;
	}
	PNODE p =queue->front->pNext;
	while(p != NULL)
	{
		cout<<p->data<<endl;
		p = p->pNext;
	}
}
bool is_empty(PQUEUE queue)
{
	if(queue->front != queue->rear)
		return false;
	else
		return true;
}
void delete_Queue(PQUEUE queue)
{
	if(is_empty(queue))
	{
		cout<<"无数据！"<<endl;
		return;
	}
	PNODE pTemp =queue->front->pNext;  //不能是queue->front 因为这个头节点是没有数据的 应该是Head中的pNext指向的节点才是第一个
	queue->front->pNext = pTemp->pNext;
	free(pTemp);

}
void Out_Queue(PQUEUE queue, int *val)
{
	if(is_empty(queue))
	{
		cout<<"队列为空，无法出队！"<<endl;
	}
	PNODE p = queue->front->pNext;
	*val = p->data;
	queue->front->pNext = p->pNext;
}
void clear(PQUEUE queue)
{
	PNODE p = queue->front->pNext;
	PNODE q = NULL;
	queue->rear =queue->front;// 把尾节点指向头节点
	queue->front->pNext =NULL;//留下没有实际数据的头节点 然后删除后面的所有元素
	while(p)
	{
		q = p;
		p = p->pNext;
		free(q);
	}
}