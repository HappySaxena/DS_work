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
// int height(Node*root){
//     if(root==NULL){
//         return 0;
//     }
//     return max(height(root->left),height(root->right))+1;
// }

// int isbalance(Node*root){

// if(root == NULL){
//     return true;
// }

// int left_height = height(root->left);
// int right_height = height(root->right);
// if(abs(left_height - right_height) > 1){
// return false;
// }
// else{
//     return isbalance(root->left) && isbalance(root->right);
// }
// }


int isbalance(Node*root){
    if(root==NULL){
        return 0;
    }
    int l_height = isbalance(root->left);
    int r_height = isbalance(root->right);
    if(l_height==-1 || r_height==-1 || abs(l_height - r_height)>1){
        return -1;
}
return 1 + max(l_height,r_height);
}
bool isbalance_pkka(Node*root){
    return isbalance(root)>0;
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
    if(isbalance_pkka(root)){
        printf("The tree is balanced");
    }
    else{
        printf("tree is imbalanced");
    }

}