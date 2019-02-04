//factorial using recursion
using namespace std;
#include<iostream>
int fact(int n){
    if(n<=1)
    return 1;
    else{
        int x = fact(n-1);
        x = x*n;
        return x;
    }
}
main()
{
    int n;
    cin>>n;
    int ans = fact(n);
    cout<<ans;
    return 0;
}