/*
 * Complete the function below.
 * Please store the size of the int array to be returned in result_size pointer. For example,
 * int a[3] = {1, 2, 3};
 * *result_size = 3;
 * return a;
 * 
 */

int* cutSticks(int n, int *a, int *result_size) 
{
  int k=0;
  int *b;
  int num=n;
  b=(int *)malloc(n*sizeof(int));
  while(num!=0)
  {
      int min=a[0];
      for(int i=1;i<n;i++){
        if(a[i]<min)
          min=a[i];
      }
      int count=0;
      for(int i=0;i<n;i++){
              if(a[i]>0){
                a[i]-=min;
                count++;
                if(a[i]==0)
                  num--;
              }
      }
      b[k++]=count;
  }
  *result_size=--k;
  return b;
}



