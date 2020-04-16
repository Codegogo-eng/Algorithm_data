#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct Queue
{
	int *pBase;//ָ�������׵�ַ
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
	int val;//��������ɾ����Ԫ�أ�
	Ini_queue(&Q);
	traversal(&Q);
	In_queue(&Q,1);
	In_queue(&Q,2);
	traversal(&Q);
	if(delete_queue(&Q,&val))
		cout<<"��ɾ���������ǣ�"<<val<<endl;
	else
		cout<<"ɾ��ʧ�ܣ�"<<endl;
	if(delete_queue(&Q,&val))
		cout<<"��ɾ���������ǣ�"<<val<<endl;
	else
		cout<<"ɾ��ʧ�ܣ�"<<endl;
	if(delete_queue(&Q,&val))
		cout<<"��ɾ���������ǣ�"<<val<<endl;
	else
		cout<<"ɾ��ʧ�ܣ�"<<endl;
	return 0;
}
void Ini_queue(PQUEUE Q)
{
	Q->pBase = new int[len];
	if(Q->pBase == NULL)
	{
		cout<<"�����ڴ�ʧ�ܣ�"<<endl;
		return;
	}
	else
	{
		Q->front = 0;
		Q->rear = 0;
		cout<<"�����ڴ�ɹ���"<<endl;
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
	if(Q->front == Q->rear ) //����Ҫ==0
		return true;
	else
		return false;
}
void In_queue(PQUEUE Q, int val)
{
	//��ӣ���Ԫ�ط���rλ���ϣ�ͬʱr�ƶ���
	if(is_full(Q))
	{
		cout<<"�����������޷���ӣ�"<<endl;
		return;
	}
	else
	{
		Q->pBase[Q->rear] = val;
		Q->rear = (Q->rear +1)%len;
		cout<<"��ӳɹ���"<<endl;
		return;
	}
}
void traversal(PQUEUE Q)
{
	if(is_empty(Q))
	{
		cout<<"�����ݣ�"<<endl;
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