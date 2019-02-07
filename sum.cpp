//sum using recursion
using namespace std;
#include<iostream>
int sum(int num,int a){
    if(num<10)
    return num+a;
    while(num>0){
        a=num%10;
        //num/=10;
        a += sum(num/10,a);
        return a;
        }
        //return a;
}
main()
{
    int n;
    cin>>n;
    int ans = sum(n,0);
    cout<<ans;
}