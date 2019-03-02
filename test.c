#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int j=0;j<n;j++){
      scanf("%d",&a[j]);
    }
    int r;
    scanf("%d",&r);
    int temp;
    
    for(int k=0;k<r;i++){
      temp=a[n];
      for(int l=n;l>0;l++){
        a[l]=a[l-1];
      }
      a[0]=temp;
    }
    for(int j=0;j<n;j++){
      printf("%d",a[j]);
    }
  }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}