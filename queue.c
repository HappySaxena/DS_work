#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data ;
    struct node* next ;
    
}Node;

Node* create_node(int x){
    Node* newnode = malloc(sizeof(Node));
newnode->next = NULL;
newnode->data = x;
return newnode;
}
void printlist(Node** front,Node** rear)
{
    Node*temp = *front;
    do{
    if((*front = NULL) && ((*rear) == NULL)){
        printf("khali hai");
    }
    else{
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    }
    while(temp != (*front));
}

void enqueue(Node**front,Node**rear,int x){
    Node* newnode = create_node(x);
    if(*front == NULL){
        *front = *rear = newnode;
    }
    else{
        (*rear)->next = newnode;
        *rear = newnode;
        (*rear)->next = *front;
        
        
    }
}
void dequeue(Node**front,Node**rear){
    if((*front)== NULL){
        printf("underflow");
        return;
    }
    Node*temp = *front;
    *front = (*front)->next;
    if((*front)!=NULL){
    (*rear)->next = *front;}
    if(temp == *rear){
*rear = NULL;
    }
    else if(temp->next == *rear){
        (*rear)->next = NULL;
        (*front)->next = NULL;
    }
    free(temp);

}

int main()
{
    Node*front = NULL;
    
    Node*rear = NULL;
    enqueue(&front,&rear,5);
    enqueue(&front,&rear,6);
    enqueue(&front,&rear,5);
    enqueue(&front,&rear,5);
    dequeue(&front,&rear);
    
 dequeue(&front,&rear);
  dequeue(&front,&rear);
   dequeue(&front,&rear);
   
 
    printlist(&front,&rear);
    
}