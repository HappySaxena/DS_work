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
Node* findintersection(Node*head1,Node*head2){
    unordered_set<Node*> visited;
    Node* p1 = head1;
    while(p1 != NULL){
        visited.insert(p1);
        p1 = p1->next;
    }
    Node* p2 = head2;
    while(p2 != NULL){
        if(visited.find(p2) != visited.end()){
            return p2;
        }
        p2 = p2->next;
    }
    return NULL;
}
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Node* head1 = NULL;
    insert(&head1,1);
    insert(&head1,3);
    insert(&head1,1);
    Node*temp = head1;
    Node* c1 = new Node;
    c1->data = 2;
    Node*c2 = new Node;
    c2->data = 4;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = c1;
    c1->next = c2;
    c2->next = NULL;

  
    // insert(&head1,6);
    // insert(&head1,7);
    // insert(&head1,8);
    // insert(&head1,9);
    Node* head2 = NULL;
    // insert(&head2,1);
    // insert(&head2,2);
    insert(&head2,3);
    temp = head2;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = c1;
    c1->next = c2;
    c2->next = NULL;


    
    // insert(&head2,6);
    // insert(&head2,7);

    Node* intersection = findintersection(head1, head2);

    if(intersection != NULL){
        cout << "Intersection found at node with data: " << intersection->data << endl;
        cout << "List 1: ";
        printList(head1);
        cout << "List 2: ";
        printList(head2);
        cout << "Intersection List: ";
        printList(intersection);
    } else {
        cout << "No intersection found." << endl;
        cout << "List 1: ";
        printList(head1);
        cout << "List 2: ";
        printList(head2);
    }
}
    

    