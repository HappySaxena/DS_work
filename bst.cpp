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
int isbst(Node*root){
    if(root == NULL)
        return 1;
    if(root->left != NULL && root->left->data > root->data)
        return 0;
    if(root->right != NULL && root->right->data < root->data)
        return 0;
    return isbst(root->left) && isbst(root->right);
}
int sum(Node*root){
    if(root == NULL)
        return 0;
    return root->data + max(sum(root->left) , sum(root->right));
}
 
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->right = createNode(6);
    if(isbst(root)){
        cout<<"The tree is a BST"<<endl;
    }
    else{
        cout<<"The tree is not a BST"<<endl;
    }
    cout<<"The sum of the tree is: "<<sum(root)<<endl;

}