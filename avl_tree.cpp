#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
        struct node* left;
        struct node* right;
        int height;
        
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
        newNode->height = 1; // New node is initially added at leaf
        return newNode;
    }
    int height(Node* N){
        if(N==NULL)
            return 0;
        return N->height;
    }
    int getBalance(Node* N){
        if(N==NULL)
            return 0;
        return (height(N->left) - height(N->right));
    }
    Node * right_rotate(Node*y){
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node * left_rotate(Node*y){
        Node* x = y->right;
        Node* T2 = x->left;
        x->left = y;
        y->right = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* insert(Node*node,int key){
        if(node==NULL)
        return createNode(key);
        if(key<node->data){
            node->left = insert(node->left,key);
        }
        else if(key>node->data){
            node->right = insert(node->right,key);
        }
        else
            return node;
            node->height = 1 + max(height(node->left), height(node->right));
            int balance = getBalance(node);
            if(balance > 1 && key < node->left->data)
                return right_rotate(node);
            if(balance < -1 && key > node->right->data)
                return left_rotate(node);
            if(balance > 1 && key > node->left->data){
                node->left = left_rotate(node->left);
                return right_rotate(node);
            }
            if(balance < -1 && key < node->right->data){
                node->right = right_rotate(node->right);
                return left_rotate(node);
            }
            return node;
    }
    Node * buildavl(const vector<int>&v){
        Node* root = NULL;
        for(int i=0;i<v.size();i++){
            root = insert(root,v[i]);
        } if(balance > 1 && key < node->left->data)
        return right_rotate(node);
    if(balance < -1 && key > node->right->data)
        return left_rotate(node);
    if(balance > 1 && key > node->left->data){
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if(balance < -1 && key < node->right->data){
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
        return root;
    }
    void inorder_traversal(Node* root){
        if(root == NULL)
            return;
       
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
Node * findmin(Node*root){
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
}
Node* deletenode(Node*root,int x){
    if(root == NULL){
        return NULL;
    }
    if(x < root->data){
        root->left = deletenode(root->left,x);
    }
    else if(x>root->data){
        root->right = deletenode(root->right,x);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = findmin(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right,temp->data);
            return root;
        }
        
    }
    int balance = getBalance(root);
    if(balance > 1 && getBalance(root->left) >= 0)
        return right_rotate(root);
    if(balance < -1 && getBalance(root->right) <= 0)
        return left_rotate(root);
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
    
}

int main(){
    vector<int> v = {
        128,98,135,110,130,26,85,99,120
    };
Node* root = buildavl(v);
    cout << "Inorder traversal of the constructed AVL tree is: ";
    inorder_traversal(root);
    cout << endl;
    root = deletenode(root, 135);
    cout<< root->data;
    cout << "Inorder traversal after deletion of 1: ";
    inorder_traversal(root);
    cout << endl;
    return 0;
}