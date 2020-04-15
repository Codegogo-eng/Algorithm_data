#include<iostream>
#include<malloc.h>
using namespace std;
//定义节点
typedef struct Node
{
	int data; //数据域
	struct Node * pNext; //指针域，保存的是一个个节点的地址
}NODE,*PNODE;     //PNODE 是struct Node * 类型 为什么要使用结构体指针，因为可以通过函数调用来改变结构体变量的值。

PNODE creat_list();
void traversal(PNODE pHead);
bool is_empty(PNODE pHead);
int length(PNODE pHead);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE pHead , int pos , int *save_node);
void sort(PNODE pHead);

int main()
{
	//要创建链表，首先需要创建头指针
	PNODE pHead = NULL;
	pHead = creat_list();
	traversal(pHead);
	is_empty(pHead);
	

	//insert_list(pHead,2,5);
	//traversal(pHead);

	cout<<"**********"<<endl;
	//int len = length(pHead);
	//cout<<"链表的长度为："<<len<<endl;
	sort(pHead);
	traversal(pHead);
	//int val = 0;//保存链表中被删除的元素
	//delete_list(pHead,3 ,&val);
	//cout<<"被删除的元素为："<<val<<endl;
	return 0;
}
PNODE creat_list()
{
	//首先需要明确的有效节点的个数
	int len = 0;
	int i = 0;
	int value;
	cout<<"Please cout the length of the list: ";
	cin>>len;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));

	PNODE p = pHead; //表示尾节点
	p->pNext = NULL;
	//在给每个有效节点进行赋值
	for(i=0;i<len;i++)
	{
		cout<<"Please cout the value of the node: ";
		cin>>value;

		//每次赋值时产生新的指针域
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = value;

		//现在需要将每次产生的新节点挂在尾节点之后
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
		p = p->pNext; //指针移动
	}
	cout<<endl;

	return;
}

bool is_empty(PNODE pHead)
{
	if(pHead->pNext == NULL)
	{
		cout<<"链表为空！"<<endl;
		return true;
	}
	else
	{
		cout<<"链表不为空！"<<endl;
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
		p=p->pNext;//这样写因为最后一个节点的指针域为NULL，所以没有算最后一个
	}
	return i;
}

bool insert_list(PNODE pHead, int pos ,int val) //pos表示有效节点数 从0开始
{
	int len = length(pHead);
	if(pos < 0 ||pos >len)
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	/* //这个是下标从0开始
	//PNODE p = pHead->pNext;
	//p = p->pNext;
	for(int i = 0;i < pos - 1;i++) //插入是将指针指向插入位置的前一位
		p = p->pNext;
		*/
	/* //这种就是从1开始 因为这个是p里面是pHead的地址，而p->pNext是pHead下一个的地址，总得都是pos-1
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
	for(i = 0, p=pHead->pNext;i< len - 1;i++,p = p->pNext) //类似于数组排序
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
