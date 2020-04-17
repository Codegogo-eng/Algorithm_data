/*
������ʽ�������������ȡ��С������ַ��ʷ�ʽ���з���
����Ϊ��ABCDEFGH
����Ϊ��BDCEAFHG
����Ϊ��DECBHGFA
*/
#include<iostream>
using namespace std;

typedef struct BNode
{
	char data;
	struct BNode * pLchild;
	struct BNode * pRchild;
}BNODE, *PBNODE;

PBNODE CreatBtree();
void PreTraserval(PBNODE pT);
void InTraserval(PBNODE pT);
void PostTraserval(PBNODE pT);
int main()
{
	BNODE * pT = CreatBtree();
	PreTraserval(pT);
	cout<<"*************"<<endl;
	InTraserval(pT);
	cout<<"*************"<<endl;
	PostTraserval(pT);
	cout<<"*************"<<endl;
	return 0;
}
PBNODE CreatBtree()
{
	PBNODE pA = new BNODE;
	PBNODE pB = new BNODE;
	PBNODE pC = new BNODE;
	PBNODE pD = new BNODE;
	PBNODE pE = new BNODE;
	PBNODE pF = new BNODE;
	PBNODE pG = new BNODE;
	PBNODE pH = new BNODE;
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pF->data = 'F';
	pG->data = 'G';
	pH->data = 'H';
	pA->pLchild = pB;
	pA->pRchild = pF;
	pB->pLchild = NULL;
	pB->pRchild = pC;
	pC->pLchild = pD;
	pC->pRchild = pE;
	pD->pLchild = pD->pRchild = NULL;
	pE->pLchild = pE->pRchild = NULL;
	pF->pLchild = NULL;
	pF->pRchild = pG;
	pG->pLchild = pH;
	pG->pRchild = NULL;
	pH->pLchild = pH->pRchild = NULL;
	return pA;
}
void PreTraserval(PBNODE pT)
{
	//���õݹ�ʵ����������α�㷨Ϊ��
	/*
	�ȷ��ʸ��ڵ㣬�ڷ������������ٷ���������������ÿ�����ڵ���˵�������һ���ݹ�
	*/
	if(pT != NULL)
	{
		cout<<pT->data<<endl;
		if(pT->pLchild != NULL)
		{
			PreTraserval(pT->pLchild);
		}
		if(pT->pRchild != NULL)
		{
			PreTraserval(pT->pRchild);
		}
	}
}
void InTraserval(PBNODE pT)
{
	/*
	������ʣ��ȷ������������ڷ��ʸ��ڵ㣬�ٷ���������
	*/
	if(pT != NULL)
	{
		if(pT->pLchild != NULL)
		{
			InTraserval(pT->pLchild);
		}
		
		cout<<pT->data<<endl;
		if(pT->pRchild != NULL)
		{
			InTraserval(pT->pRchild);
		}
	}
}
void PostTraserval(PBNODE pT)
{
	//�����ȷ������������ڷ����������������ʸ��ڵ�
	if(pT != NULL)
	{
		if(pT->pLchild != NULL)
		{
			PostTraserval(pT->pLchild);
		}
		if(pT->pRchild != NULL)
		{
			PostTraserval(pT->pRchild);
		}
		
		cout<<pT->data<<endl;
	
	}
	
}