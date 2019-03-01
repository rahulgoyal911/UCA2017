// using namespace std;
// #include<iostream>
// int binSearch(int a[],int n,int start,int end){
//     int mid = start + (end-start)/2;
//     if(n==a[mid])
//         return mid;
//     if(a[mid]<n){
//         binSearch(a,n,mid+1,end);
//     }
//     else
//     {
//        binSearch(a,n,start,mid-1);
//     }
    
// }
// int main()
// {
//     int a[] = {1,2,3,4,5,6,7,8,9};
//     int ind = binSearch(a,1,0,9);
//     cout<<ind;
//     return 0;
// }


using namespace std;
#include<iostream>
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void printa(int a[],int n){
    for(int i=0;i<=n;i++)
    cout<<a[i]<<"  ";
    cout<<endl;
}
int partition(int a[],int start,int end){
    int i = start-1;
    int pivot = a[end];
    for(int j=start;j<end;j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[end]);
    return i+1;

}
void quickSort(int a[],int start,int end){
if(start<end){
    int pivotindex = partition(a,start,end);
    quickSort(a, start, pivotindex - 1);
    quickSort(a, pivotindex + 1, end);
}

}
int main()
{
    int a[] = {1,3,5,2,-4,0,4,65,8,7,3};
    printa(a,10);
    quickSort(a,0,10);
    printa(a,10);

}