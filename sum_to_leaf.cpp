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

bool ispath(Node*root,int sum){
    if(root == NULL){
        return false;
    }
    if(root->data == sum && root->left ==NULL && root->right==NULL){
        return true;
    }
    return ispath(root->left,(sum-(root->data))) || ispath(root->right,(sum-(root->data)));
}


int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(9);
    root->right->left = createNode(7);
    root->left->right->left = createNode(6);
       root->left->right->left->right = createNode(0);
if (ispath(root,7)){
    printf("yesssss");
}
else{
    printf("noooo");
}
}