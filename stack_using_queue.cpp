#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}
Node;
Node* createNode(int x){
    Node* newNode = new Node;
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->next = NULL;
    
    newNode->data = x;
    return newNode;
}
void push(int x,queue<Node*>&q1,queue<Node*>&q2){
    Node* newNode = createNode(x);
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    q1.push(newNode);
    
}
Node* top(queue<Node*>&q1,queue<Node*>&q2){
    if(q1.empty() && q2.empty()){
        cout<<"Stack is empty";
        return NULL;
        
    }
    else if(!q1.empty()){
        Node* newNode = q1.back();
        cout<<newNode->data;
       return newNode;
    }
    else{
        Node*newnode = q2.back();
        cout<<newnode->data;
        return newnode;

    
}
}
bool empty(queue<Node*>&q1,queue<Node*>&q2){
    if(q1.empty() && q2.empty()){
        return true;
    }
    else{
        return false;
    }
}
void pop(queue<Node*>&q1,queue<Node*>&q2){
    if(q1.empty() && q2.empty()){
        cout<<"stack is empty";
        return;
    }
    while(q1.size()>1){
        q2.push(q1.front());
        q1.pop();
       
}
q1.pop();
while(!q2.empty()){
    q1.push(q2.front());
    q2.pop();
}
}

int main(){
   
    
   
  
    queue<Node*>q1;
    queue<Node*>q2;
    push(1,q1,q2);
    push(2,q1,q2);
    push(3,q1,q2);
    push(4,q1,q2);
    pop(q1,q2);
    
   
    cout<<endl;
   
    cout<<"Top element is: ";
    top(q1,q2);
    cout<<endl;
}