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
void insert(Node**head,int x){
    Node* newnode = createNode(x);
    if((*head) == NULL){
        *head = newnode;
    }
    else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
int three_int(int x){
for(int i=2;(i*i*i <= x);i++){
    if(x%i == 0){
        for(int j = (i+1);sqrt(x/i);j++){
            if((x/i)%j == 0){
                for(int k = j+1;k<=sqrt(x/(i*j));k++){
                    if((x/(i*j))%k == 0){
                        return 1;
                    }
                }
            }
        }
    
}
   return 0;
    
}
void reverse(Node**head){
    Node*prev = (*head);
    Node*current = (*head)->next;
    Node*next = current->next;
    while(current != NULL){
        current->next = prev;
        prev = current;
        current = next;
        if(next != NULL){
            next = next->next;
        }
    }
    (*head)->next = NULL;
    (*head) = prev;
    }


int main(){
    int n;
    cout<<"Enter the number of linked lists: ";

    cin>>n;
    vector<Node*> v(n,NULL);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(&v[i],x);
}
for(int i = 0;i<n;i++){
    cout<<v[i]->data<<" ";

}
int i;
cout<<"Enter the index of linked list to be reversed: ";
cin>>i;

insert(&v[i],0);
insert(&v[i],1);
insert(&v[i],2);
insert(&v[i],3);
insert(&v[i],4);
insert(&v[i],5);

reverse(&v[i]);
cout<<"The reversed linked list is: ";
Node* temp = v[i];
while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
}
cout<<endl;
int a = three_int(30);
cout<<a<<endl;

}