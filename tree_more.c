#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}
Node;
Node* createNode(int x){
    Node* newNode = malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = x;
    return newNode;
}
int depth(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    return 1 + (left>right?left:right);
}
int diameter(Node*root){
    if(root==NULL){
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    return 1 + left + right;
}
void balance(Node*root){
    if(root==NULL){
        return;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    if(abs(left-right)<=1){
        printf("Balanced\n");
    }
    else{
        printf("Not balanced\n");
    }
}
int child_sum(Node*root){
    if(root==NULL){
        return 1;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int left = 0;
    int right = 0;
    if(root->left!=NULL){
        left = root->left->data;
    }
    if(root->right!=NULL){
        right = root->right->data;
    }
    if(root->data == left+right){
        return child_sum(root->left) && child_sum(root->right);
    }
    else{
        return 0;
    }
}

int main(){
    // Node* root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);
    // root->right->right->left = createNode(10);
    //  root->right->right->left->left = createNode(90);
    //   root->right->right->left->right = createNode(10);
    //    root->right->right->left->right->left = createNode(10);

        Node* root = createNode(6);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(2);
    root->left->right = createNode(0);
   int dia =  diameter(root);
   printf("Diameter of the tree is %d\n",dia);
balance(root);
int a = child_sum(root);    
if(a==1){
    printf("Child sum property satisfied\n");
}
else{
    printf("Child sum property not satisfied\n");
}


    return 0;
}