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
Node* binary_tree(vector<int>& numbers, int l, int r){
    if(l>r)
        return NULL;
    int mid = (l+r)/2;
    Node* root = createNode(numbers[mid]);
    root->left = binary_tree(numbers,l,mid-1);
    root->right = binary_tree(numbers,mid+1,r);
    return root;
}
void inorder_traversal(Node* root){
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

Node* findmin(Node*root){
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
    return root;
}
int sum(Node*root,int i){
    
    if(root == NULL)
        return 0;
        if(i == 0)
       { root->left = NULL;
       }
    return (sum(root->left,++i) + sum(root->right,++i)) + root->data;
}
Node* makesum(Node*root){
    if(root == NULL)
    {
        return NULL;
    }
    root->data = sum(root,0);
    makesum(root->left);
    makesum(root->right);

return root;
}


int main(){
    vector<int> numbers ={
        40,60,50,33,55,11,52,23
};
sort(numbers.begin(),numbers.end());

Node* root = NULL;
root = binary_tree(numbers,0,numbers.size()-1);

cout<<endl;
root = deletenode(root,40);
inorder_traversal(root);
cout<<endl;
root = makesum(root);
inorder_traversal(root);
cout<<endl;


}