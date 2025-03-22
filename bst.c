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
    if(left>right){
        return NULL;
        }
        if(left==right){
            Node* newnode = createNode(arr[left]);
           
            return newnode;
        }
int mid = (left+right)/2;
Node* newnode = createNode(arr[mid]);

newnode->left = make_bst(arr,left,mid-1);
newnode->right = make_bst(arr,mid+1,right);
return newnode;
    }


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
     Node* root = NULL;
   root = make_bst(arr,0,11);
    printf("%d\n",root->data);
    printf("%d\n",root->left->data);
    printf("%d\n",root->right->data);
    printf("%d\n",root->left->left->data);
    printf("%d\n",root->left->right->data);
    printf("%d\n",root->right->left->data);
    printf("%d\n",root->right->right->data);
    


    return 0;
}