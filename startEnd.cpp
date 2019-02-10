using namespace std;
#include<iostream>
int count=0;
int flag=0;
int f(char a[]){
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==' '){
            if(flag==true){
                cout<<a[i-1];
                flag=false;
            }
        }
        else{
            if(flag==false){
                cout<<a[i];
                flag=true;
            }
        }
    }
}
int main(){
    char str[]=" my name is rahul   ";
	f(str);
    return 0;
}