/*��n�Ľ׳� ��ŵ��
�ݹ���ʵֻҪ��n��n-1�Ĺ�ϵ���ɡ��ȼ���n-1��״̬�Ѿ�ȫ�������ˣ�
��ô˼����n-1��α��n���������ΰ�n��n-1���һ������
*/
#include<iostream>
using namespace std;

int g(int n)
{
	if(n == 1)  //������൱������ֹ����
		return 1;
	else
		return n +g(n-1);
}
void hannuota(int n, char A, char B, char C) //A������ʼ�� B��������� C����Ŀ���� ABC����һ����ָABC
{
	if(n == 1)
	{
		cout<<"��"<<n<<"��"<<A<<"�ƶ���"<<C<<endl;
	}
	else
	{
		hannuota(n-1,A,C,B);
		cout<<"����"<<n<<"������"<<A<<"�ƶ���"<<C<<endl;
		hannuota(n-1,B,A,C);
	}
}
int main()
{
	char A = 'A';
	char B = 'B';
	char C = 'C';
	int n = 7;
	hannuota(n ,A,B,C);
	return 0;
}
