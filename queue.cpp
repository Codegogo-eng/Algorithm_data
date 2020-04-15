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
	cout<<"���ӵ�ֵΪ��"<<val<<endl;
	traversal(&queue);
	//Out_Queue(&queue, &val);
	//cout<<"���ӵ�ֵΪ��"<<val<<endl;
	//traversal(&queue);
	cout<<"---------"<<endl;
	clear(&queue);
	traversal(&queue);
	return 0;
}
void ini_Queue(PQUEUE queue)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	pHead->pNext =NULL; //��Ϊ��ֵ ��һ������Ҫ��
	if(pHead == NULL)
	{
		cout<<"�����ڴ�ʧ�ܣ�"<<endl;
		return;
	}
	else
	{
		queue->front = pHead;
		queue->rear = pHead;
		cout<<"���г�ʼ���ɹ���"<<endl;
		return;
	}
}
void push_Queue(PQUEUE queue, int val)
{
	//�����½ڵ�
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
		cout<<"�����ݣ�"<<endl;
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
		cout<<"�����ݣ�"<<endl;
		return;
	}
	PNODE pTemp =queue->front->pNext;  //������queue->front ��Ϊ���ͷ�ڵ���û�����ݵ� Ӧ����Head�е�pNextָ��Ľڵ���ǵ�һ��
	queue->front->pNext = pTemp->pNext;
	free(pTemp);

}
void Out_Queue(PQUEUE queue, int *val)
{
	if(is_empty(queue))
	{
		cout<<"����Ϊ�գ��޷����ӣ�"<<endl;
	}
	PNODE p = queue->front->pNext;
	*val = p->data;
	queue->front->pNext = p->pNext;
}
void clear(PQUEUE queue)
{
	PNODE p = queue->front->pNext;
	PNODE q = NULL;
	queue->rear =queue->front;// ��β�ڵ�ָ��ͷ�ڵ�
	queue->front->pNext =NULL;//����û��ʵ�����ݵ�ͷ�ڵ� Ȼ��ɾ�����������Ԫ��
	while(p)
	{
		q = p;
		p = p->pNext;
		free(q);
	}
}