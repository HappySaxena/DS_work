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
// Node* merged_tree(Node*root1,Node*root2){
//     if(root1==NULL && root2==NULL){
//         return NULL;
//     }
//     Node*root3 = createNode(0);
//     if(root1!=NULL && root2!=NULL){
//         root3->data = root1->data + root2->data;
//          root3->left = merged_tree(root1->left,root2->left);
//     root3->right = merged_tree(root1->right,root2->right);
//         return root3;
//     }
//     if(root1==NULL && root2!=NULL){
//         root3->data = root2->data;
//         root3->left = merged_tree(NULL,root2->left);
//     root3->right = merged_tree(NULL,root2->right);
//         return root3;
//     }
//     // if(root1!=NULL && root2==NULL){
//         root3->data = root1->data;
//         root3->left = merged_tree(root1->left,NULL);
//     root3->right = merged_tree(root1->right,NULL);
//         return root3;
//     // }

// }
Node* merged_tree(Node*root1,Node*root2){
if(root1==NULL && root2 == NULL){
    return NULL;
}
 if(root1!=NULL && root2!=NULL){
    root1->data = root1->data + root2->data;
    root1->left = merged_tree(root1->left,root2->left);
    root1->right = merged_tree(root1->right,root2->right);
    return root1;
}
if(root1==NULL && root2!=NULL){
     root1-> left= merged_tree(NULL,root2->left);
     root1->right = merged_tree(NULL,root2->right);

    return root2;
}
if(root1!=NULL && root2==NULL){
    root1->left = merged_tree(root1->left,NULL);
      root1->right = merged_tree(root1->right,NULL);
    return root1;
}

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

    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    
    root1->left->right = createNode(5);
    root1->right->right = createNode(9);
    
    root1->left->right->left = createNode(6);

    Node* merged_node = merged_tree(root,root1);
    printf("%d",merged_node->left->right->left->data);
}