#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next ;
    struct node* prev;
}Node;

Node* createnode(int x){
    Node* newnode = new(Node); // redundancy here....
    if(newnode==NULL){
        printf("memory allocation failed");
        exit(1);
    }
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = x;
    return newnode;
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
void reverse_group(Node**head,int k){
    int count = 1;
    Node* current = (*head)->next;
    Node* prev = (*head);
    Node* next = current->next;
    Node*prev_all = *head;
    while(current!=NULL)
    {
       
    while(count<k)
    {
        if(prev != NULL)
        {
            current->next = prev->prev;
        }
        else
        {
            current->next = NULL;
        }
        
        current->prev = next->next;
        prev = current;
        current = next;
        next = next->next;
        count++;
    }
    prev_all->next = current->prev;
 
    prev_all = current;
    prev = current;
    current = next;
    next = next->next;
count = 1;

}
}
int main(){
Node* head = NULL;
insertnode(&head,1);
insertnode(&head,2);
insertnode(&head,3);
insertnode(&head,9);
insertnode(&head,6);
insertnode(&head,2);
insertnode(&head,7);
insertnode(&head,36);
insertnode(&head,8);
insertnode(&head,20);
printlist(&head);
int k;
cout<<endl;
cout<<"Enter the number : ";
cin>>k;
reverse_group(&head,k);
printlist(&head);
return 0;




}