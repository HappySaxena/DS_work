#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data ;
    int p_value;
    struct node* next ;
    
    
}Node;

Node* create_node(int x,int p){
    Node* newnode = malloc(sizeof(Node));
newnode->next = NULL;
newnode->data = x;
newnode->p_value = p;
return newnode;
}
void enqueue(Node**front,Node**rear,int x,int p){
    Node* newnode = create_node(x,p);
    if(*front == NULL){
        *front = *rear = newnode;
    }
    
    (*rear)->next = newnode;
    newnode->next = *front;
    *rear = newnode;
}
void dequeue(Node**front,Node**rear){
    if(*front == NULL && *rear == NULL){
printf("khali hai");
    }
    int max = 0 ;
    Node*temp = *front;
    
    do{
        if(temp->p_value>max){
            max = temp->p_value;
        }
        temp = temp->next;
        
    }
    while(temp!=*front );
    temp = *front;
    Node* previous = *front;   // remember the thing
    
     do{
        if(temp->p_value == max && temp!=(*front)){
            previous->next = temp->next;
            free(temp);
            return;
            temp = previous->next;
        }
        else if(temp->p_value == max && temp == *front){
*front = (*front)->next;
free(temp);
temp = *front;
        }
        else{
            previous = temp;
        temp = temp->next;
         
    }
}while(temp!=*front);
}
int peek(Node**front,Node**rear){
    Node*temp = *front;
    int max = 0;
  do{
        if(temp->p_value>max){
            max = temp->p_value;
        }
        temp = temp->next;
        
    }
    while(temp!=*front );
    temp = *front;
     
     do{
        if(temp->p_value == max){
            return temp->data;
        }
        else{
            
        temp = temp->next;
        
    }
     }
    while(temp!=(*front));

}
void printlist(Node**front,Node**rear){
    if(*rear == NULL && *front == NULL){
        printf("khali hai");
    }
    Node* temp = *front;
    int i = 0;
    while(temp!=*front || i == 0){
        printf("%d->",temp->data);
        temp = temp->next;
        i++;
    }
}
// enquue
// dequeue
// peek
int main(){
    Node* rear = NULL;
    Node* front = NULL;
    enqueue(&front,&rear,10,5);
    enqueue(&front,&rear,16,5);
    enqueue(&front,&rear,19,1);
     enqueue(&front,&rear,178,15);
      enqueue(&front,&rear,199,15);
    printlist(&front,&rear);
    printf("\n");
    // dequeue(&front,&rear);
     int a = peek(&front,&rear);
     printf(" peak element is %d",a);
     printf("\n");
     dequeue(&front,&rear);
      dequeue(&front,&rear);
      
     
     
     printlist(&front,&rear);


}