#include<bits/stdc++.h>

using namespace std;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}
Node;
Node* createNode(int x){
    Node* newNode = new(Node);
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = x;
    return newNode;
}
void level_order(Node*root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int levelsize = q.size();
        for(int i=0;i<levelsize;i++){
            Node*newnode = q.front();
            q.pop();
            cout<< newnode->data << " ";
            if(newnode->left!=NULL){
                q.push(newnode->left);
            }                                             
            if(newnode->right!=NULL){
                q.push(newnode->right);
            }    

    }
        }
        }
//////RECURSIVE APPROACH.....

int height(Node*root){
    if(root==NULL){
        return 0;
}
else{
    return 1 + max(height(root->left),height(root->right));
}
}
// void print_that(Node*root,int level){
//     if(root==NULL){
//         return;
//         }
//         if(level==1){void level_order(Node*root){
// //     int h = height(root);
// //     for(int i=0;i<h;i++){
// //         print_that(root,i+1);
// //     }
// // }
//             cout<<root->data<<" ";
//         }
// if(level>1){
//     print_that(root->left,level-1);
//     print_that(root->right,level-1);

//  }
 //void level_order(Node*root){
// //     if(root==NULL){
// //         return;
// //     }
// //     queue<Node*> q;
// //     q.push(root);
// //     while(!q.empty()){
// //         int levelsize = q.size();
// //         for(int i=0;i<levelsize;i++){
// //             Node*newnode = q.front();
// //             q.pop();
// //             cout<< newnode->data << " ";
// //             if(newnode->left!=NULL){
// //                 q.push(newnode->left);
// //             }
// //             if(newnode->right!=NULL){
// //                 q.push(newnode->right);
// //             }    

// //     }
// //         }
// //         }
// }
// void level_order(Node*root){
//     int h = height(root);
//     for(int i=0;i<h;i++){
//         print_that(root,i+1);
//     }
// }
int main(){
       Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->right->left = createNode(10);
    root->right->right->right = createNode(11);
    level_order(root);
}