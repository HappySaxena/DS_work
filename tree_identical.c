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
void invert(Node*root){
    if(root==NULL){
        return;
    }
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert(root->left);
    invert(root->right);

}
int similar(Node*root1,Node*root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }
    if(root1==NULL || root2==NULL){
        return 0;
    }
    if(root1->data!=root2->data){
        return 0;
    }
    return similar(root1->left,root2->left) && similar(root1->right,root2->right);
}
void symetric(Node*root){
    if(root==NULL){
        return;
    }
   int a =  similar(root->left,root->right);
    if(a==1){
         printf("Symetric\n");
    }
    else{
         printf("Not symetric\n");
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


    //  Node* root1 = createNode(1);
    // root1->left = createNode(2);
    // root1->right = createNode(3);
    // root1->left->left = createNode(4);
    // root1->left->right = createNode(5);
    // root1->right->left = createNode(6);
    // root1->right->right = createNode(7);
    // root1->right->right->left = createNode(10);
  
// int a = similar(root,root1);
// if(a==1){
//     printf("Both trees are identical\n");
// }
// else{
//     printf("Both trees are not identical\n");
// }
// invert(root);
// printf("Inverted tree is\n");
// printf("Root:%d\n",root->data);
// printf("Left:%d\n",root->left->data);
// printf("Right:%d\n",root->right->data);
// printf("Left:%d\n",root->left->left->data);
// printf("Right:%d\n",root->left->right->data);
// printf("Left:%d\n",root->right->left->data);
// printf("Right:%d\n",root->right->right->data);


symetric(root);
    return 0;
}