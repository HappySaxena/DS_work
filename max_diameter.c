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
int max_dia(Node*root,int *dia){
if(root==NULL){
    return 0;
}
int left_height = max_dia(root->left,dia);
int right_height = max_dia(root->right,dia);
*dia = (*dia>1+left_height+right_height)?*dia:(1+left_height+right_height);
return (left_height>right_height?left_height:right_height )+ 1;

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
  int * dia;   //nowhere pointing....
    int dia = 0;
    int a = max_dia(root,&dia);
    printf("%d",(dia));

}