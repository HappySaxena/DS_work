#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* createNode(int x){
    Node* newnode = new Node;
    if(newnode == NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void push(Node**head,int x,Node**top){
    
    Node* newnode = createNode(x);
    if((*head) == NULL){
        *head = newnode;
        *top = newnode;
    }
    else{(*top)->next = newnode;
        (*top) = (*top)->next;
    }
     }
     void pop(Node**head,Node**top){
        if((*head)==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp = *head;
        while(temp->next != *top){
            temp = temp->next;
        }
        delete *top;
        *top = temp;
        temp->next = NULL;
        if(*top == NULL){
            *head = NULL;
        }
     }
    



int main(){
    Node* head = NULL;
    Node* top = NULL;
    push(&head,1,&top);
    push(&head,2,&top);
    push(&head,3,&top);
    push(&head,4,&top);
    pop(&head,&top);
    pop(&head,&top);
    pop(&head,&top);
    cout<<top->data<<endl;



}