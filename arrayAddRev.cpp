//we dont have the array size
//the array ends when -1 occurs
//complexity must be n/2
//we have to add reverse of array to array
#include<iostream>
using namespace std;
 static int flag=0;
void f(int a[],int i,int j)
{
   
	static int c=-1;
	if(a[j]==-1)
	{
		c=i;
		return;
	}
	else if(a[j+1]==-1)
	{
		c=i+1;
		return;
	}
	else
	{
		f(a,i+1,j+2);
		if(a[i]!=a[c])
        flag=1;
		c++;
	}
}
// void f(int a[],int i,int j)
// {
// 	static int c=-1;
// 	if(a[j]==-1)
// 	{
// 		c=i;
// 		return;
// 	}
// 	else if(a[j+1]==-1)
// 	{
// 		c=i+1;
// 		return; 
quickSortInbuilt.cpp: In function ‘int main()’:
quickSortInbuilt.cpp:19:33: error: invalid conversion from ‘int (*)(void*, void*)’ to ‘__compar_fn_t {aka int (*)(const void*, const void*)}’ [-fpermissive]
     qsort(a,11,sizeof(int),compa);
                                 ^
In file included from /usr/include/c++/7/cstdlib:75:0,
// 	}
// 	else
// 	{
// 		f(a,i+1,j+2);
// 		a[i]=a[i]+a[c];
// 		a[c]=a[i];
// 		c++;
// 	}
// }
/*
void f(int a[],int i,int j)
{
	static int c;
	if(a[j-1]==-1)
	{
		c=i+1;
		return;
	}
	else if(a[j]==-1)
	{
		c=i+1;
		return;
	}
	else
	{
		f(a,i+1,j+2);
		a[i]=a[i]+a[c];
		a[c]=a[i];
		c++;
	}
}
*/
int main()
{
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
	f(a,0,0);
    if(flag==0)
    cout<<"yes";
    else
    cout<<"no";
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<a[i]<<" ";
	// }
}