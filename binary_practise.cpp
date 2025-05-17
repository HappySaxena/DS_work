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
int height(Node*root){
    if(root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return min(left,right)+1;
}

int main(){
    Node* root = NULL;
    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(18);
    root->right->right->left = createNode(20);

    cout<<"Height of the tree is: "<<height(root)<<endl;
}