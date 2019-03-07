using namespace std;
#include<iostream>
struct node{
    int data;
    struct node *next;
}*start,*ptr,*result,*head;

void reverse(node *current) 
    { 
        // Initialize current, previous and 
        // next pointers 
        struct node *prev = NULL, *next = NULL;
        head = NULL; 

        while (current != NULL) 
        { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's p, *next = NULLpointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    }
void printInReverse(node *ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        printInReverse(ptr->next);
        cout<<ptr->data<<endl;
    }
void printLinked(node *ptr){
    while(ptr != NULL) {
        
        cout<<ptr->data<<endl;
        ptr = ptr->next;           
    
    }
}
void insertValues(node *ptr){
     for(int i=0;i<3;i++){
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=(i+1)*10;
        ptr->next=NULL;
        start->next = ptr;
        start = start->next;
    }
}
int main()
{
    start = (struct node*)malloc(sizeof(struct node));
    //initialising
    start->data=NULL;
    start->next=NULL;
    
    ptr=start;
    result=start;

    //inserting data into linkedlist
   insertValues(ptr);
    ptr=result;
    //printing linkedlist
    printLinked(ptr);
    cout<<endl;

    //print linkedlist in reverse order
    ptr=result;
    printInReverse(ptr);
    cout<<endl;

    //reversing a linkedlist
    ptr=result;
    reverse(ptr);

    //printing final reversed linkedlist
    ptr=head;
    printLinked(ptr);
    cout<<endl;


    return 0;
}