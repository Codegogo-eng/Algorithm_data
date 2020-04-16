/*求n的阶乘 汉诺塔
递归其实只要找n和n-1的关系即可。先假设n-1个状态已经全部做好了，
那么思考由n-1如何变成n，最后在如何把n和n-1变成一个整体
*/
#include<iostream>
using namespace std;

int g(int n)
{
	if(n == 1)  //这个就相当于是终止条件
		return 1;
	else
		return n +g(n-1);
}
void hannuota(int n, char A, char B, char C) //A代表起始盘 B代表借助盘 C代表目的盘 ABC并不一定是指ABC
{
	if(n == 1)
	{
		cout<<"将"<<n<<"从"<<A<<"移动到"<<C<<endl;
	}
	else
	{
		hannuota(n-1,A,C,B);
		cout<<"将第"<<n<<"个盘由"<<A<<"移动到"<<C<<endl;
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
