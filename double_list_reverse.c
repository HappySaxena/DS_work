#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next ;
    struct node* prev;
}Node;

Node* createnode(int x){
    Node* newnode = malloc(sizeof(Node)); // redundancy here....
    if(newnode==NULL){
        printf("memory allocation failed");
        exit(1);
    }
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = x;
}
void insertnode(Node** head,int x){
    Node* newnode = createnode(x);
    if(*head==NULL){
        *head = newnode;
        return;
    }
    Node* temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    }
void printlist(Node**head){
    Node* temp = *head;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp = temp->next;
        }
        printf("\n");
}
void reverse(Node**head){
    Node* temp = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }
}

int main(){
Node* head = NULL;
insertnode(&head,1);
insertnode(&head,2);
insertnode(&head,3);

printlist(&head);
reverse(&head);
printlist(&head);

}
