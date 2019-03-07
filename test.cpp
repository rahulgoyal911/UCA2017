using namespace std;
#include<iostream>
struct Node{
    int data;
    struct Node *next;
}*finala;
void insert(struct Node *temp){
    for(int i=1;i<4;i++){
        struct Node *ptr;
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = 10*i;
        ptr->next = NULL;
        temp->next = ptr;
        temp = temp->next; 

    }

}
void print(struct Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
void printrev(struct Node *temp){
    if(temp==NULL){
    return;
    }
    printrev(temp->next);
 //   cout<<temp->data<<endl;
}
struct Node *copyList(struct Node *org)
{
struct Node *new1,*start,*ptr;
start = (struct Node *)malloc(sizeof(struct Node));
ptr=start;
 
 //start->data = NULL;
 start->next=NULL;

  while(org!=NULL){
    start->data = org->data;
    start->next=NULL;
   
     new1 = (struct Node *)malloc(sizeof(struct Node));
   //  new1->data = NULL;
     new1->next=NULL;
   	start->next = new1;
    start = start->next;
    org = org->next;
  }
  return ptr;
}
void reverse(struct Node *temp){

}
int main()
{
    struct Node *start;
    start = (struct Node *)malloc(sizeof(struct Node));
    start->data = NULL;
    start->next = NULL;

    struct Node *temp;
    temp = start;
    insert(temp);


    temp = start;
   // print(temp);

    temp = start;
    printrev(temp);

    temp = start;
    finala = copyList(temp);

   // temp = start;
    print(finala);
    return 0;
}