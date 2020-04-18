//快速排序
#include<iostream>
using namespace std;
int FindPos(int *a, int low, int hight)
{
	int val = a[low];
	while(low < hight)
	{
		while(low < hight && a[hight] >= val)
			--hight;
		a[low] = a[hight];
		while(low < hight && a[low] <= val)
			low++;
		a[hight] = a[low];
	}
	a[low] = val;//不可忘却
	return low;

}
void My_sort(int a[], int low, int hight)
{
	int pos = 0;
	if(low < hight)
	{
		pos = FindPos(a,low,hight);
		My_sort(a,low,pos-1);
		My_sort(a,pos+1,hight);
	}
}
int main()
{
	int a[8] = {9,0,8,10,-5,2,13,7};
	My_sort(a,0,7);
	for(int i=0;i<8;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}