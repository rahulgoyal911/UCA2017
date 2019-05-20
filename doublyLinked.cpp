#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

// Insert in Beginning
void insertBeg(struct Node** head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data  = data;     //  Insert data in new node
  node->next = *head;   // link new node at beginning of list
  node->prev=NULL;
  if(*head != NULL)
    (*head)->prev=node;
  *head = node;  // Change the head to new node.
}

// Insert after a given data
void insertAfter(struct Node* prev, int data)
{
  if (prev == NULL)
  {
    printf("the given previous node cannot be NULL");
    return;
  }
  struct Node* node =(struct Node*) malloc(sizeof(struct Node));
  node->data  = data;     //  Insert data in new node
  node->next = prev->next;   // link new node after prev node
  node->prev = prev;
  prev->next->prev=node;
  prev->next = node;  // Link the previous node to new node.
}

// Insert before a given data
void insertBefore(struct Node* next, int data)
{
  if (next == NULL)
  {
    printf("the given next node cannot be NULL");
    return;
  }
  struct Node* node =(struct Node*) malloc(sizeof(struct Node));
  node->data  = data;     //  Insert data in new node
  next->prev->next = node;   // link next of previous node to new node
  node->prev = next->prev;    // Link the prev of new node
  next->prev = node;      // Link the prev of next node
  node->next = next;  // Link the nextof new node to next.
}

// Insert at the end of list
void insertEnd(struct Node* head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  struct Node *last = head;
  node->data  = data;     //  Insert data in new node
  node->next = NULL;   // link new node to NULL as it is last node
  if (head == NULL)  // if list is empty add in beginning.
  {
    head = node;
    node->prev=NULL;
    return;
  }
  while (last->next != NULL)  // Find the last node
    last = last->next;
  last->next = node;  // Add the node after the last node of list
  node->prev=last;
  return;
}

// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main()
{
  struct Node* head = NULL;
  printf("Linked List = ");
  printList(head);
  insertBeg(&head, 6);    // At Beginning
  printf("Linked List = ");
  printList(head);
  insertBeg(&head, 2);    // At Beginning
  printf("Linked List = ");
  printList(head);
  insertAfter(head, 4);   // After Head node
  printf("Linked List = ");
  printList(head);
  insertEnd(head, 8);    // At End
  printf("Linked List = ");
  printList(head);
  insertAfter(head->next, 5); // After 2nd Node
  printf("Linked List = ");
  printList(head);
  insertBefore(head->next, 3); // Before 2nd Node
  printf("Linked List = ");
  printList(head);
  return 0;
}
