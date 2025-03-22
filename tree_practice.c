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


// void inorder_traversel(Node*root){
//     if(root==NULL){
//         return;
//     }
//     inorder_traversel(root->left);
//     printf("%d ",root->data);
// inorder_traversel(root->right);
// }
Node* mirror_tree(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    // Create a new node with the same data
    Node* root1 = createNode(root->data);

    // Recursively mirror left and right subtrees
    root1->left = mirror_tree(root->right);
    root1->right = mirror_tree(root->left);

    return root1;
}

int identical(Node*root,Node*root1){
    if(root==NULL && root1==NULL){
return 1;
}
if(root!=NULL && root1!=NULL){
    if(root->data==root1->data){
        return identical(root->left,root1->left) && identical(root->right,root1->right);
}
else{
    return 0;
}
}
return 0;
}
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(8);
    root->right->right = createNode(4);

  
    Node* root1 = NULL;
    root1 = mirror_tree(root);
    printf("%d ",root1->data);
    printf("%d ",root1->left->data);
     printf("%d ",root1->right->data);
     printf("%d ",root1->right->left->data);
     printf("%d ",root1->right->right->data);
     printf("%d ",root1->left->right->data);
    printf("%d \n",root1->left->left->data);

    int a = identical(root,root1);
    if(a==1){
        printf("yesss");
    }
    else{
        printf("no");
    }


   

    
}