#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next = NULL;
    
}Node;
void insert(Node** head,int x){
    Node*newNode = new Node;
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = x;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node*temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int main(){
    
    Node* head1 = NULL;
    insert(&head1,1);
    insert(&head1,2);
    insert(&head1,3);
    insert(&head1,4);
    insert(&head1,5);
    insert(&head1,6);
    insert(&head1,7);
    insert(&head1,8);
    insert(&head1,9);
    Node* head2 = NULL;
    insert(&head2,1);
    insert(&head2,2);
    insert(&head2,3);
    insert(&head2,4);
    insert(&head2,5);
    insert(&head2,6);
    insert(&head2,7);
    Node*p1 = head1;
    Node*p2 = head2;
    Node*head3 = NULL;
    int c = 0;
    int x = 0,y = 0;    
    while(p1!=NULL || p2!=NULL){
       if(p1!=NULL)
        x = p1->data;else
        x = 0;
        if(p2!=NULL)
         y = p2->data;else
         y = 0;
       int val = x+y+c;
         c = val/10;
            val = val%10;
            insert(&head3,val);
    }
    p1 = head1;
    p2 = head2;
    Node*temp = head3;
    while(p1!=NULL){
        cout << p1->data << " ";
        p1 = p1->next;
    }
    cout << endl;
    while(p2!=NULL){
        cout << p2->data << " ";
        p2 = p2->next;
    }
    cout << endl;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}