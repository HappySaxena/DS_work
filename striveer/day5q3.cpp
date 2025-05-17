#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;
void insert(Node** head, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    if(*head == NULL){
        *head = new_node;
        new_node->next = NULL;
    }
    else{
        Node* last = *head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }
}
    
    void printList(Node* node){
        while(node != NULL){
            cout << node->data << " ";
            node = node->next;
        }
    }
Node * merge(Node* head1, Node* head2){
    Node *p1,*p2,*p3;
int flag = 0;
    if(head1->data >= head2->data){
         p1 = head1;
         p2 = head2;
         p3 = head2->next;
         flag = 1;
        }
         else{
            p1 = head2;
            p2 = head1;
            p3 = head1->next;
            
         }
     while(p1!=NULL && p2!=NULL && p3!=NULL){
    
     
     if(p1->data >= p2->data && p1->data < p3->data){
         Node*temp = new Node();
         temp->data = p1->data;
         p2->next = temp;
         temp->next = p3;
         p1 = p1->next;
     }
         p2 = p2->next;
         p3 = p3->next;
     
 }
     if(p3 == NULL){
         while(p1!=NULL){
             Node*temp = new Node();
             temp->data = p1->data;
             p2->next = temp;
             temp->next = NULL;
             p1 = p1->next;
             p2 = p2->next;
         }
         p2->next = NULL;
     }
     if(flag == 1){
        return head2;
     }
     else{
        return head1;
     }
 }
    int main(){
        Node* head1 = NULL;
        Node* head2 = NULL;
        int n1, n2;
        cout << "Enter the number of elements in the first linked list: ";
        cin >> n1;
        cout << "Enter the elements of the second linked list: ";
        cin >> n2;
        for(int i = 0; i < n1; i++){
            int x;
            cin >> x;
            insert(&head1, x);
        }
        for(int i = 0; i < n2; i++){
            int x;
            cin >> x;
            insert(&head2, x);
        }

       Node*merged = merge(head1, head2);
        cout << "The merged linked list is: ";
        printList(merged);
        cout << endl;
 
    
    
        
        return 0;
    
    }