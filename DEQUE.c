#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data ;
    struct node* next ;
    struct node* prev ;
    
}Node;

Node* create_node(int x){
    Node* newnode = malloc(sizeof(Node));
newnode->next = NULL;
newnode->data = x;
newnode->prev = NULL;
return newnode;
}
void insertion_begin(Node**front,Node**rear,int x){
    Node* newnode = create_node(x);
    if(*front == NULL){
        *front = *rear = newnode;
       
    }
    else{
        newnode->next = *front;
        (*front)->prev = newnode;
        *front = newnode;

    }
}
void deletion_last(Node**front,Node**rear){
   Node*temp = *rear;
    if(*front == NULL && *rear == NULL){
        printf("underflow");
        return ;
    }
    else{
        *rear = (*rear)->prev;
        (*rear)->next = NULL;
        free(temp);
    }
    
}
void deletion_begin(Node**front,Node**rear){
    Node*temp = *front;
    if(*front == NULL && *rear == NULL){
        printf("underflow");
        return ;
    }
    else{
        *front = (*front)->next;
        (*front)->prev = NULL;
        free(temp);
       
    }
}
void insertion_last(Node**front,Node**rear,int x){
    Node* newnode = create_node(x);
    if(*front == NULL){
        *front = *rear = newnode;
       
    }
    else{
        (*rear)->next = newnode;
        newnode->prev = *rear;
        *rear = newnode;
       
    }
}

void printlist(Node**front,Node**rear){
    Node*temp = *front;
    if(temp == NULL)
    {
        printf("khali hai");
        return;
    }
    while(temp!= NULL){
    
    
        printf("%d->",temp->data);
        temp = temp->next;
    }
    }
    
    

int main()
{
    Node*front = NULL;
    Node*rear = NULL;
    insertion_begin(&front,&rear,7);
     insertion_begin(&front,&rear,9);
      insertion_begin(&front,&rear,10);
       insertion_last(&front,&rear,10);
        insertion_last(&front,&rear,15);
        printlist(&front,&rear);
 

 



    
}