using namespace std;
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

char board[80][80];
vector<struct snake> s{4};
int length=4;
int lastx,lasty;
int score=0;
void eatFood();
struct food{
    int x;
    int y;
    char value='F';
}f;
struct snake{
    int x;
    int y;
    char value;
};
void border(){
    for(int i=0;i<80;i++){
        for(int i=0;i<80;i++){
            for(int j=0;j<80;j++){
                if(i==0 || j==0 ||i==79 ||j==79){
                    board[i][j]='I';
                }
                else{
                    board[i][j]=' ';
                }
            }
        }
    }
}
void print()
{
    for(int i=0;i<80;i++){
     for(int j=0;j<80;j++){
         if(i==0 || j==0 ||i==79 ||j==79){
                    board[i][j]='I';
                }
         if(board[i][j]!=0)
         cout<<board[i][j];
         else
         {
             cout<<" ";
         }
         
     }
     cout<<endl;
 }

}
void createSnake()
{
        s[0].x=40;
        s[0].y=40;
        s[0].value='H';
        s[1].x=40;
        s[1].y=41;
        s[1].value='#';
        s[2].x=40;
        s[2].y=42;
        s[2].value='#';
        s[3].x=40;
        s[3].y=43;
        s[3].value='T';
        for(int i=0;i<length;i++){
            board[s[i].x][s[i].y]=s[i].value;
        }

}
void moveup(){
    int lasttempx = s[length-1].x;
    int lasttempy=s[length-1].y;
    int tempx=s[0].x;
    int tempy=s[0].y;
    int tempval = s[0].value;
    if(s[0].x==0){
        s[0].x+=79;
    }
    s[0].x-=1;
    s[0].y-=0;
    for(int i=length-1;i>1;i--){
         s[i].x=s[i-1].x;
         s[i].y=s[i-1].y;
    }
    s[1].x=tempx;
    s[1].y=tempy;
    s[length].value=' ';
    for(int i=0;i<length;i++){
            board[s[i].x][s[i].y]=s[i].value;
        }
        board[lasttempx][lasttempy]=' ';
        if( s[0].x == f.x && s[0].y == f.y ){
            eatFood();
        }
        lastx=s[length].x;
        lasty=s[length].y;

        if(s[0].x>79){
            s[0].x-=79;
        }
        if(s[0].y>79){
            s[0].y-=79;
        }
        if(s[0].x<0){
            s[0].x+=79;
        }
        if(s[0].y<0){
            s[0].y+=79;
        }
    system("clear");
    print();
}
void movedown(){
    int lasttempx = s[length-1].x;
    int lasttempy=s[length-1].y;
    int tempx=s[0].x;
    int tempy=s[0].y;
    int tempval = s[0].value;
    s[0].x+=1;
    s[0].y+=0;
    for(int i=length-1;i>1;i--){
         s[i].x=s[i-1].x;
         s[i].y=s[i-1].y;
    }
    s[1].x=tempx;
    s[1].y=tempy;
    s[length].value=' ';
    for(int i=0;i<length;i++){
            board[s[i].x][s[i].y]=s[i].value;
        }
        board[lasttempx][lasttempy]=' ';
        if( s[0].x == f.x && s[0].y == f.y ){
            eatFood();
        }
        lastx=s[length].x;
        lasty=s[length].y;
        if(s[0].x>79){
            s[0].x-=79;
        }
        if(s[0].y>79){
            s[0].y-=79;
        }
        if(s[0].x<0){
            s[0].x+=79;
        }
        if(s[0].y<0){
            s[0].y+=79;
        }
    system("clear");
    print();

}
void moveleft(){
    int lasttempx = s[length-1].x;
    int lasttempy=s[length-1].y;
    int tempx=s[0].x;
    int tempy=s[0].y;
    int tempval = s[0].value;
    if(s[0].y==0){
        s[0].y+=79;
    }
    s[0].x-=0;
    s[0].y-=1;
    for(int i=length-1;i>1;i--){
         s[i].x=s[i-1].x;
         s[i].y=s[i-1].y;
    }
    s[1].x=tempx;
    s[1].y=tempy;
    s[length].value=' ';
    for(int i=0;i<length;i++){
            board[s[i].x][s[i].y]=s[i].value;
        }
        board[lasttempx][lasttempy]=' ';
        if( s[0].x == f.x && s[0].y == f.y ){
            eatFood();
        }
        lastx=s[length].x;
        lasty=s[length].y;
        if(s[0].x>79){
            s[0].x-=79;
        }
        if(s[0].y>79){
            s[0].y-=79;
        }
        if(s[0].x<0){
            s[0].x+=79;
        }
        if(s[0].y<0){
            s[0].y+=79;
        }
    system("clear");
    print();

}
void moveright(){
 
    int lasttempx = s[length-1].x;
    int lasttempy=s[length-1].y;
    int tempx=s[0].x;
    int tempy=s[0].y;
    int tempval = s[0].value;
    s[0].x-=0;
    s[0].y+=1;
    for(int i=length-1;i>1;i--){
         s[i].x=s[i-1].x;
         s[i].y=s[i-1].y;
    }
    s[1].x=tempx;
    s[1].y=tempy;
    s[length].value=' ';
    for(int i=0;i<length;i++){
            board[s[i].x][s[i].y]=s[i].value;
        }
        board[lasttempx][lasttempy]=' ';
        if( s[0].x == f.x && s[0].y == f.y ){
            eatFood();
        }
        lastx=s[length].x;
        lasty=s[length].y;
        if(s[0].x>79){
            s[0].x-=79;
        }
        if(s[0].y>79){
            s[0].y-=79;
        }
        if(s[0].x<0){
            s[0].x+=79;
        }
        if(s[0].y<0){
            s[0].y+=79;
        }
    system("clear");
    print();

}
void generateFood()
{
    board[f.x][f.y]='F';
    system("clear");
    print();
}
void eatFood()
{
    score+=10;
    f.x= rand() % 50+20; 
    f.y= rand() % 50+20;

    struct snake ob;

    ob.x=lastx;
    ob.y=lasty;
    ob.value='T';

    s.push_back(ob);

    length++;
    s[length-2].value='#';
     board[s[length-2].x][s[length-2].y]='#';
     print();
    generateFood();
}
int main()
{
    f.x= rand() % 50+20; 
    f.y= rand() % 50+20;
border();
createSnake();
print();
generateFood();
char input;
int gameon=1;
while(gameon){
    cin>>input;
    if(input=='w'){
        moveup();
    }
    else if(input=='s'){
        movedown();
    }
    else if(input=='a'){
        moveleft();
    }
    else if(input=='d'){
        moveright();
    }
    else if(input=='q'){
        //quit;
        cout<<"Your final score is "<<score<<endl;
        break;
    }
    else{
        //wrong input
    }

}
cout<<"Game finished";
//print();
    
}