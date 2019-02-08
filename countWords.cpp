using namespace std;
#include<iostream>
int count=0;
int flag=0;
int f(char a[]){
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==' '){
            flag=false;
        }
        else{
            if(flag==0){
                count++;
                flag=true;
            }
        }
    }
}
int main(){
    char str[]=" my name is rahul   ";
	f(str);
    cout<<count;
    return 0;
}