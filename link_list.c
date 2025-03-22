#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int a;
    struct node* next ;
}Node;

Node* createnode(int x){
    Node* newnode = malloc(sizeof(Node)); // redundancy here....
    if(newnode==NULL){
        printf("memory allocation failed");
        exit(1);
    }
    newnode->next = NULL;
    newnode->a = x;
return newnode;

}
void insert(Node**head,int x){
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
}

void printlist(Node**head){
    Node* temp = *head;
    while(temp!=NULL){
        printf("%d->",temp->a);
        temp = temp->next;
    }
    printf("\n");
}
void reverse()

int main(){
    Node* head = NULL;
    insert(&head,1);
    insert(&head,10);
    insert(&head,9);
    insert(&head,7);
    printlist(&head);
}
