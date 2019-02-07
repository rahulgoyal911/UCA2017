using namespace std;
#include<iostream>
int mat[4][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
void calSum(int i,int j,int sum){
    if( i>=4 && j<0 && j>=5)
    return;
    else{
sum = sum + mat[i][j];
    calSum(++i,--j,sum);
    calSum(++i,--j,sum);
    if(sum==40)
    cout<<"yes";
    }
    
}
int main()
{
    int row,col;
    cin>>row>>col;
    calSum(row,col,0);
    return 0;
}
