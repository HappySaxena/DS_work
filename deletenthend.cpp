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
    int k;
    cin >> k;
    Node* head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    insert(&head,7);
    insert(&head,8);
    insert(&head,9);
    Node*prev = head;
    Node*slow = head;
    Node*temp = head;
    while(k--){
        prev= temp;
        temp = temp->next;
        
    }
    if(temp==NULL && prev!= NULL){
        head = head->next;
        temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        return 0;
    }
    if(temp==NULL && prev==NULL){
        cout << "k is greater than the length of the linked list";
        return 0;
    }
    prev= head;
    Node*fast = temp;
    while(fast!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    free(slow);
    temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

   
}
