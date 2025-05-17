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
    insert(&head1,3);
    insert(&head1,1);
    insert(&head1,2);
    insert(&head1,4);
    // insert(&head1,6);
    // insert(&head1,7);
    // insert(&head1,8);
    // insert(&head1,9);
    Node* head2 = NULL;
    // insert(&head2,1);
    // insert(&head2,2);
    insert(&head2,3);
    insert(&head2,2);
    insert(&head2,4);
    // insert(&head2,6);
    // insert(&head2,7);

    Node*p1 = head1;
    Node*p2 = head2;
    int flag = 0;
    while(flag!=1 && p2!=NULL){
    while(p1!=NULL ){
        if(p1->data == p2->data && p1->next->data == p2->next->data){
            flag = 1;
            break;
        
        }
    p1 = p1->next;
}if(flag == 0){
            p2 = p2->next;
            p1 = head1;
        }
    }
    if(flag == 1){
        cout << "The intersection point is: " << p1->data;
    }
    else{
        cout << "No intersection point";
    }
}





