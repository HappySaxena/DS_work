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


int main(){
    Node* head = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(&head, x);
    }
    cout << "The linked list is: ";
    printList(head);
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<< "The middle element is: " << slow->data << endl;
    cout << endl;
    return 0;

}