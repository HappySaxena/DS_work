#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}
Node;
Node* createNode(int x){
    Node* newNode = new Node;
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = x;
    return newNode;
}


int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    // root->right->right = createNode(9);
    // root->right->left = createNode(7);
    root->left->right->left = createNode(6);
    // root->left->right->left->right = createNode(0);
     queue<Node*> q;
     q.push(root);
     vector<int>v;
     while(!q.empty()){
        int n = q.size();
        Node*temp = q.front();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        q.pop();
        v.insert(v.begin(),temp->data);
        for(int i=1;i<n-1;i++){
            Node*temp = q.front();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            q.pop();
        }
        temp = q.front();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        v.push_back(temp->data);
        q.pop();
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

            
       

   
}