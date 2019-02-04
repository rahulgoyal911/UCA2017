using namespace std;
#include<iostream>
int secondMax(int *a,int size)
{
    int max = a[0];
    int second=0;
    int i;
    for(i=1;i<size;i++){
        if(a[i]>max){
            second = max;
            max = a[i];
            break;
        }
        else if(a[i]<max){
            second=a[i];
            break;
        }
    }
    if(!second){
        second = a[size];
    }
    int j;
    for(j=i;j<size;j++){
       if(a[j]>max){
            second = max;
            max = a[j];
        }
        else if(a[j]<max){
            second=a[j];
        }
    }

return second;
}
main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = secondMax(a,n);
    cout<<ans;
}