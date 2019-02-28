using namespace std;
#include<iostream>
main()
{
    int a[]={1,3,5,7,9,11,13,15,17};
    int left,right;
    int x = 17;
    left=0;
    right=9;
    int ans;
    
    while(left<=right){
        int mid = left + (right-left)/2;
        if(x==a[mid]){
            ans = mid;
            break;
        }
        
        if(a[mid]>x){
            right = mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<ans;
    return 0;
}

// #include<stdio.h>

// int rec_binary_search(int arr[], int left, int right, int x) {
//   int result;
//   if (right >= left) {
//     int mid = left + (right - left)/2;
//     if (arr[mid] == x)  return mid;
//     if (arr[mid] > x) return rec_binary_search(arr, left, mid-1, x);
//     result = rec_binary_search(arr, mid+1, right, x);
//     return result;
//   }
//   return -1;       // when element is not present in array.
// }

// int main() {
//   int loc,x,array[]={10,11,12,13,14,25,26,37,48,29};
//   x=11;        // element to be searched in the array
//   loc=rec_binary_search(array,0,10,x);
//   if(loc != -1)
//     printf("Element found at location : %d",loc);
//   else
//     printf("Element not present in the array.");
//   return 0;
// }
