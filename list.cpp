#include<iostream>
#include<malloc.h>
using namespace std;
//����ڵ�
typedef struct Node
{
	int data; //������
	struct Node * pNext; //ָ���򣬱������һ�����ڵ�ĵ�ַ
}NODE,*PNODE;     //PNODE ��struct Node * ���� ΪʲôҪʹ�ýṹ��ָ�룬��Ϊ����ͨ�������������ı�ṹ�������ֵ��

PNODE creat_list();
void traversal(PNODE pHead);
bool is_empty(PNODE pHead);
int length(PNODE pHead);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE pHead , int pos , int *save_node);
void sort(PNODE pHead);

int main()
{
	//Ҫ��������������Ҫ����ͷָ��
	PNODE pHead = NULL;
	pHead = creat_list();
	traversal(pHead);
	is_empty(pHead);
	

	//insert_list(pHead,2,5);
	//traversal(pHead);

	cout<<"**********"<<endl;
	//int len = length(pHead);
	//cout<<"����ĳ���Ϊ��"<<len<<endl;
	sort(pHead);
	traversal(pHead);
	//int val = 0;//���������б�ɾ����Ԫ��
	//delete_list(pHead,3 ,&val);
	//cout<<"��ɾ����Ԫ��Ϊ��"<<val<<endl;
	return 0;
}
PNODE creat_list()
{
	//������Ҫ��ȷ����Ч�ڵ�ĸ���
	int len = 0;
	int i = 0;
	int value;
	cout<<"Please cout the length of the list: ";
	cin>>len;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));

	PNODE p = pHead; //��ʾβ�ڵ�
	p->pNext = NULL;
	//�ڸ�ÿ����Ч�ڵ���и�ֵ
	for(i=0;i<len;i++)
	{
		cout<<"Please cout the value of the node: ";
		cin>>value;

		//ÿ�θ�ֵʱ�����µ�ָ����
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = value;

		//������Ҫ��ÿ�β������½ڵ����β�ڵ�֮��
		p->pNext = pNew;
		pNew->pNext = NULL;
		p = pNew;
	}
	return pHead;

}

void traversal(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(p != NULL)
	{
		cout<<p->data<<"\t";
		p = p->pNext; //ָ���ƶ�
	}
	cout<<endl;

	return;
}

bool is_empty(PNODE pHead)
{
	if(pHead->pNext == NULL)
	{
		cout<<"����Ϊ�գ�"<<endl;
		return true;
	}
	else
	{
		cout<<"����Ϊ�գ�"<<endl;
		return false;
	}
}

int length(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int i=0;
	while(p != NULL)
	{
		i++;
		p=p->pNext;//����д��Ϊ���һ���ڵ��ָ����ΪNULL������û�������һ��
	}
	return i;
}

bool insert_list(PNODE pHead, int pos ,int val) //pos��ʾ��Ч�ڵ��� ��0��ʼ
{
	int len = length(pHead);
	if(pos < 0 ||pos >len)
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	/* //������±��0��ʼ
	//PNODE p = pHead->pNext;
	//p = p->pNext;
	for(int i = 0;i < pos - 1;i++) //�����ǽ�ָ��ָ�����λ�õ�ǰһλ
		p = p->pNext;
		*/
	/* //���־��Ǵ�1��ʼ ��Ϊ�����p������pHead�ĵ�ַ����p->pNext��pHead��һ���ĵ�ַ���ܵö���pos-1
	int i=0;
	PNODE p =pHead;
	while(p!=NULL &&i <pos-1 )
	{
		p = p->pNext;
		i++;
	}
	*/
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;

}
bool delete_list(PNODE pHead , int pos , int *save_node)
{
	PNODE p = pHead->pNext;
	int len = length(pHead);
	if(pos < 0 || pos>len)
		return false;
	for(int i = 0;i < pos -1;i++)
		p = p->pNext;
	*save_node = p->pNext->data;

	PNODE r = p->pNext;
	p->pNext = p->pNext->pNext;
	free(r);
	r = NULL;
	return true;
}
void sort(PNODE pHead)
{
	PNODE p,q;
	int i,j,temp;
	int len = length(pHead);
	for(i = 0, p=pHead->pNext;i< len - 1;i++,p = p->pNext) //��������������
	{
		for(j = i+1 ,q = p->pNext;j < len;j++, q=q->pNext)
		{
			if(p->data > q->data)
			{
				temp =p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
		
	}
}
