#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
Node* createnode(int x){
    Node *newnode = malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void create_list(Node**head,int x){
    Node* newnode = createnode(x);
    Node*temp = *head;
    if(*head==NULL){
        temp = *head = newnode;
return;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        temp = newnode;
    }
}
void reverse(Node**head){
    if(*head==NULL){
        return;
    }
    if((*head)->next->next==NULL){
        Node*temp = (*head)->next ;
        temp->next = *head;
        (*head)->next = NULL;
        (*head) = temp;
           }
           else{
    Node*prev = *head;
    Node*current = (*head)->next;
    Node*next = current->next;
    while(next!=NULL){
        if(prev == *head)
        {current->next = prev;
        prev-> next= NULL;
        prev = current;
        current = next;
        next = next->next;}
        else{
            current->next = prev;
            prev = current;
            current = next;
            next = next->next;
        }
    }
     current->next = prev;
    *head = current;
}}
void printlist(Node**head){
    Node*temp = *head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
}

int main(){
     Node* head = NULL;
    create_list(&head,5);
     create_list(&head,7);
       
             
    printlist(&head);
    reverse(&head);
    printf("\n");
    printlist(&head);


}
