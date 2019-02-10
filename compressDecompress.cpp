using namespace std;
#include<iostream>
void compress(char str[]){
    int k=0;
    int ch=str[0];
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==ch){
            count++;
        }
        else{
            str[k++]=ch;
            //cout<<count;
            char temp = (char)count;
            cout<<temp;
            str[k++]=count+'0';
            ch=str[i];
            count=1;
        }
    }
    str[k++]=ch;
    str[k++]=count+'0';

    str[k]='\0'; 
}
void decompress(char str[]){
    
}
int main()
{
    char str[]="aaaabbcccccddddd";
    cout<<str<<endl;
    compress(str);
    cout<<str<<endl;
    decompress(str);
    cout<<str<<endl;

}