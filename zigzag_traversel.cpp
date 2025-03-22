#include<bits/stdc++.h>


using namespace std;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}
Node;
Node* createNode(int x){
    Node* newNode = new(Node);
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = x;
    return newNode;
}
void zigzag(Node*root,int level){
    if(root==NULL)
    return;
   
    stack<Node*>s1;
    stack<Node*>s2;
    
    s1.push(root);
    if((level%2)==0){
        while(!s1.empty()){
            Node* temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            s2.push(temp->left);
            if(temp->right)
            s2.push(temp->right);
            s1 = s2;
        while(!s2.empty()){
            s2.pop();
        }

        }
        level ++;
    }
      
        else{
            while(!s1.empty()){
                Node* temp = s1.top();
                s1.pop();
                cout<<temp->data<<" ";
                if(temp->right)
                s2.push(temp->right);
                if(temp->left)
                s2.push(temp->left);
                s1 = s2;
        while(!s2.empty()){
            s2.pop();
        }
            }
            level++;
        }

        }
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->right->left = createNode(10);
    root->right->right->right = createNode(11);
    zigzag(root,0);
}