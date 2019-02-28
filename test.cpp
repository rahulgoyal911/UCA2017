using namespace std;
#include<iostream>
void printa(int a[],int n){
    for(int i=0;i<=n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int low,int high){
    int pivot = a[high];
    int ind=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            ind++;
            swap(&a[ind],&a[j]);
            
        }
    }
    swap(&a[ind+1],&a[high]);
    return ind+1;
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int pivotIndex = partition(a,low,high);
        quicksort(a,low,pivotIndex-1);
        quicksort(a,pivotIndex+1,high);
    }
    
}
int main()
{
    int a[] = {9,7,5,7,0,2,5,8,14,18,11,999,2};//0-12
    cout<<"initial array"<<endl;
    printa(a,12);
    quicksort(a,0,12);
    cout<<"after sorting"<<endl;
    printa(a,12);
    return 0;
}