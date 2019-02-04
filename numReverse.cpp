//reverse number using recursion
//two ways
#include<iostream>
using namespace std;
/*
int reverse(int n,int rev)
{
	if(n<1)
	{
		rev=rev+n;
		return rev;
	}
	else
	{
		rev=rev*10+n%10;
		rev=reverse(n/10,rev);
	}	
	return rev;
}
*/
int reverse(int n,int rev)
{
	static int d=1;
	if(n>10)
	{
		int k=n%10;
		rev=reverse(n/10,rev);
		d=d*10;
		rev=k*d+rev;
		return rev;
	}
	else
	{
		return n*d;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<reverse(n,0);
}