#include<iostream>
using namespace std;
static int flag=0;
char temp;
void f(char a[],int i,int j)
{
   
	static int c=-1;
	if(a[j]=='\0')
	{
		c=i;
		return;
	}
	else if(a[j+1]=='\0')
	{
		c=i+1;
		return;
	}
	else
	{
		f(a,i+1,j+2);
		temp=a[i];
        a[i]=a[c];
        a[c]=temp;
		c++;
	}
}
int main()
{
	char str[]="abcd";
	f(str,0,0);
    cout<<str;
    return 0;
}