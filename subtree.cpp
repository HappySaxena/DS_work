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
void issubtree(Node*root, Node*subroot){
    if(root==NULL){
        return ;
    }
    if(root->data != subroot->data){
      issubtree(root->left,subroot);
      issubtree(root->right,subroot);
    }
    if(root->data==subroot->data){
        if(similar(root,subroot)){
            printf("yess");
        }
        else{
            if
            printf("NOOO");
        }
    }
    printf("nooo\n");
    return;
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(7);

  
    root->left->right = createNode(5);
    root->right->right = createNode(9);
     root->right->left = createNode(4);

    Node*root1 = createNode(13);
    root1->left = createNode(10);
    root1->right = createNode(90);
   
  issubtree(root,root1);
}