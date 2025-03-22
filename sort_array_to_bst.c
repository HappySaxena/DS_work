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
Node* make_bst(int arr[],int left,int right){
    if(left > right){
        return NULL;
    }
    

    int mid = (left + right)/2;
    Node* root = createNode(arr[mid]);
    root->left = make_bst(arr,left,mid - 1);
    root->right = make_bst(arr,mid + 1,right);
    
  

return root;

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

int arr[] = {2,6,9,23,30,34,40,56,67,69,80,85};
Node*root = make_bst(arr,0,10);

printf("%d",root->data);
printf("%d",root->left->left->data);

}