using namespace std;
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<fstream>

char board[80][80];
vector<struct snake> s{4};
int length=0;
int lastx,lasty;
int score=0;
bool death;
char input;
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
void createSnake(char choice)
{
    if(choice=='n'){
        //prev game
        //read
        ifstream ifs;
        ifs.open("tempfile.txt");

        int initial=0;
        while(s[length-1].value!='T'){
            ifs>>s[length].x;
            ifs>>s[length].y;
            ifs>>s[length++].value;
            // s[length].y>>ifs;
            // s[length++].value>>ifs;
        }
        length;
        ifs.close();
      //  cout<<"closed";
    }
    else if(choice=='m'){
        //new game
        //write
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
        s[3].value='#';
        s[4].x=40;
        s[4].y=44;
        s[4].value='T';
        length=5;
    }
        
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
    else{
        s[0].x-=1;
    s[0].y-=0;

    if(s[0].x==s[1].x){
       s[0].x+=1; 
    }
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

    if(s[0].x==s[1].x){
       s[0].x-=1; 
    }
    else{

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
    if(s[0].y==s[1].y){
       s[0].y+=1; 
    }
   else{
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
    if(s[0].y==s[1].y){
       s[0].y-=1; 
    }
    else{
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
     system("clear");
     print();
    generateFood();
}
void checkdeath(){
    for(int i=1;i<length;i++){
        if(s[0].x==s[i].x && s[0].y==s[i].y){
            input='q';
        }
    }
    death=true;

}
int main()
{
    cout<<"press n to continue previous game and press m for new game \n";
    char choice;
    cin>>choice;
    f.x= rand() % 50+20; 
    f.y= rand() % 50+20;
border();
createSnake(choice);
system("clear");
print();
generateFood();
int gameon=1;
while(gameon){
    cin>>input;
    if(input=='w'){
        moveup();
        checkdeath();
    }
    else if(input=='s'){
        movedown();
        checkdeath();
    }
    else if(input=='a'){
        moveleft();
        checkdeath();
    }
    else if(input=='d'){
        moveright();
        checkdeath();
    }
    if(input=='q'){
        //quit;
        if(death==true){
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
        s[3].value='#';
        s[4].x=40;
        s[4].y=44;
        s[4].value='T';
        length=5;
        death=false;
        }
        fstream ost;
        ost.open("tempfile.txt");
        for(int i=0;i<length;i++){
            ost<<s[i].x<<endl;
            ost<<s[i].y<<endl;
            ost<<s[i].value<<endl;
        }
        ost.close();
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