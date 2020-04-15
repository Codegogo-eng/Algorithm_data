#include<iostream>
using namespace std;
struct Array
{
	int * pBase;//数组首地址
	int len;//长度
	int cnt;//当前数组元素个数
};
void ini_array(struct Array * array,int);
void show_array(struct Array * array);
bool is_empty(struct Array * array);
bool is_full(struct Array * array);
bool append(struct Array * array,int Element);
bool insert(struct Array * array,int pos,int Element);
bool clear_array(struct Array * array);
bool delete_array(struct Array * array,int pos);
void sort_array(struct Array * array);
void inversion_arr(struct Array * array);
void swap(int*,int*);
int main()
{
	struct Array array;
	ini_array(&array,6);
	//show_array(&array);
	append(&array,1);
	//show_array(&array);
	append(&array,2);
	show_array(&array);
	cout<<"-----------"<<endl;
	insert(&array,0,3);
	show_array(&array);
	insert(&array,1,4);
	show_array(&array);
	cout<<"-----------"<<endl;
	//clear_array(&array);
	//show_array(&array);
	//delete_array(&array,1);
	insert(&array,2,5);
	show_array(&array);
	cout<<"-----------"<<endl;
	//sort_array(&array);
	//show_array(&array);
	inversion_arr(&array);
	show_array(&array);
	return 0;

}
void ini_array(struct Array * array,int length)
{
	//array = (struct Array *)malloc(sizeof(struct Array)*length);
	(*array).pBase=(int *)malloc(sizeof(int)*length);//这里分配的是结构体之中的指针的空间，而不是给
	//结构体变量分配内存空间，结构体变量在创建的时候就已经分配了空间
	//建立数组很重要的一步，通过分配内存就可以创建数组，但是是不是需要回收内存？
	if(array->pBase == NULL)
	{
		cout<<"The array is empty!"<<endl;
		exit(-1);//这个程序结束
	}
	else
	{
		array->cnt=0;
		array->len=length;
	}
}
bool is_empty(struct Array * array)
{
	if(array->pBase==NULL)
		return true;
	else
		return false;
}
bool is_full(struct Array * array)
{
	if(array->cnt==(*array).len)
		return true;
	else
		return false;
}
void show_array(struct Array * array)
{
	if(is_empty(array))
	{
		cout<<"The array is empty!"<<endl;
	}
	else
	{
		for(int i=0;i<array->cnt;i++)
			cout<<array->pBase[i]<<endl;
	}
}
bool append(struct Array * array,int Element)
{
	if(is_full(array))
		return false;
	else
	{
		array->pBase[(*array).cnt]=Element;
		(array->cnt)++;//最好写成这种形式，而不要写成array->cnt++的形式。
		return true;
	}
}
bool insert(struct Array * array,int pos,int Element)
{
	if(pos<0||pos>array->cnt)
		return false;
	if(is_full(array))
		return false;
	else
	{
		//插入在当前位置后  所有的元素都向后移动一位
		//先把这个位置后所有的元素向后移，在插入
		//后移操作
		(array->cnt)++;
		for(int i=array->cnt;i>=pos;i--)
		{
			array->pBase[i]=array->pBase[i-1];
		}
		array->pBase[pos]=Element;
		return true;
	}
}
bool clear_array(struct Array * array)
{
	//长度，元素为0，释放掉内存
	array->cnt=0;
	array->len=0;
	free(array->pBase);
	array->pBase=NULL;
	return true;
}
bool delete_array(struct Array * array,int pos)
{
	if(is_empty(array))
		return false;
	else
	{
		//删除就是当前位置以后的数进行前移，且元素个数减1
		for(int i=pos;i<array->cnt;i++)
			array->pBase[i]=array->pBase[i+1];
		(array->cnt)--;
		return true;
	}
}
void sort_array(struct Array * array)
{
	if(is_empty(array))
		cout<<"The array can't sort!"<<endl;
	else
	{
		for(int i=0;i<array->cnt;i++)
		{
			for(int j=0;j<array->cnt-i-1;j++)
			{
				if(array->pBase[j]<array->pBase[j+1])
				{
					int temp = array->pBase[j];
					array->pBase[j]=array->pBase[j+1];
					array->pBase[j+1] = temp;
				}
			}
		}
	}
}
void swap(int *a,int *b)//&a &b
{
	//cout<<"a is "<<a<<endl;
	//cout<<"b is "<<b<<endl;
	int temp=*a;
	*a=*b;
	*b=temp;
	//cout<<"a is "<<a<<endl;
	//cout<<"b is "<<b<<endl;
}
void inversion_arr(struct Array * array) 
{
	int num = (array->cnt)/2;
	for(int i=0;i<num;i++)
	{
		swap(&(array->pBase[i]),&(array->pBase[array->cnt-1-i]));  
		//这实际上是*p = array->pBase[i]，所以可以直接改变地址
		//swap(array->pBase[i],array->pBase[array->cnt-1-i]); 这个也可以？指针和地址
	}
}
