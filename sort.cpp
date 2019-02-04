//sort 4 numbers using only 5 if statements
using namespace std;
#include<iostream>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int *a,int *b,int *c,int *d){
    if(*a>*b)
    swap(a,b);
    if(*c>*d)
    swap(c,d);
    if(*a>*c)
    swap(a,c);
    if(*b>*d)
    swap(b,d);
    if(*b>*c)
    swap(b,c);
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    sort(&a,&b,&c,&d);
    cout<<a<<b<<c<<d;
}
