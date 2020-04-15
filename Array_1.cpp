#include<iostream>
using namespace std;
struct Array
{
	int * pBase;//�����׵�ַ
	int len;//����
	int cnt;//��ǰ����Ԫ�ظ���
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
	(*array).pBase=(int *)malloc(sizeof(int)*length);//���������ǽṹ��֮�е�ָ��Ŀռ䣬�����Ǹ�
	//�ṹ����������ڴ�ռ䣬�ṹ������ڴ�����ʱ����Ѿ������˿ռ�
	//�����������Ҫ��һ����ͨ�������ڴ�Ϳ��Դ������飬�����ǲ�����Ҫ�����ڴ棿
	if(array->pBase == NULL)
	{
		cout<<"The array is empty!"<<endl;
		exit(-1);//����������
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
		(array->cnt)++;//���д��������ʽ������Ҫд��array->cnt++����ʽ��
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
		//�����ڵ�ǰλ�ú�  ���е�Ԫ�ض�����ƶ�һλ
		//�Ȱ����λ�ú����е�Ԫ������ƣ��ڲ���
		//���Ʋ���
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
	//���ȣ�Ԫ��Ϊ0���ͷŵ��ڴ�
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
		//ɾ�����ǵ�ǰλ���Ժ��������ǰ�ƣ���Ԫ�ظ�����1
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
		//��ʵ������*p = array->pBase[i]�����Կ���ֱ�Ӹı��ַ
		//swap(array->pBase[i],array->pBase[array->cnt-1-i]); ���Ҳ���ԣ�ָ��͵�ַ
	}
}
