//sum of digits using recursion
using namespace std;
#include<iostream>
int a=0;
int sum(int n){
    if(n==0)
    return a;
    //int a;
    a = n%10;
    a=a+sum(n/10);
}
int main()
{
    int n;
    cin>>n;
    int ans = sum(n);
    cout<<ans;
}
