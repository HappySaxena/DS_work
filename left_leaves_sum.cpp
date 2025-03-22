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
void leftleaf_sum(Node*root,Node*prev,int *sum){
    if(root==NULL){
        return;
    }

if(root->left == NULL && root->right==NULL && prev->left == root){
    (*sum) += root->data;
}
leftleaf_sum(root->left,root,sum);
leftleaf_sum(root->right,root,sum);

}


int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
  
    root->left->right = createNode(5);
    root->right->right = createNode(9);
   
  
      Node*prev = NULL;
      int sum = 0;
      leftleaf_sum(root,prev,&sum);
      cout << sum;
}