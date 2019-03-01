using namespace std;
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
void print(int a[])
{
    for(int i=0;i<11;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int compa(const void *a,const void *b){
    return *((int *)a) - *((int *)b);
}
int main()
{
    int a[] = {1,2,6,3,1,9,6,2,6,44,-4};
    print(a);
    qsort(a,11,sizeof(int),compa);
    print(a);
    return 0;
}