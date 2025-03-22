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


// void pre_order(Node*root){
//     if(root==NULL){
//         return;
//     }
//     printf("%d ",root->data);
//     pre_order(root->left);
//       pre_order(root->right);
// }
void paths(Node*root,vector <int> v){

if(root == NULL){
    return ;
}
v.push_back(root->data);
if(root->left == NULL && root->right == NULL){
    for (int i =0;i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

paths(root->left,v);
paths(root->right,v);

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
       vector <int> v;
paths(root,v);
}