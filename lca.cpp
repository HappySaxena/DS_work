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
Node* makebst(vector<int>& v,int l,int r){
    if(l>r) return NULL;
    int mid = (l+r)/2;
    Node* root = createNode(v[mid]);
    root->left = makebst(v,l,mid-1);
    root->right = makebst(v,mid+1,r);
    return root;
}
void inorder_traversel(Node* root) {
    if (root == nullptr) return;
    inorder_traversel(root->left);
    cout << root->data << " ";
    inorder_traversel(root->right);
}
void lca(Node*root,int p,int q){
    if(root ==NULL) return;
    if ((root->data > p && root->data < q) || (root->data < p && root->data > q)) {
        cout << "LCA is: " << root->data << endl;
        return;
    }
    if(root->data == p || root->data == q){
        cout << "LCA is: " << root->data << endl;
        return;
    }
    if (root->data > p && root->data > q) {
        lca(root->left, p, q);
    } else {
        lca(root->right, p, q);
    }
    

}

int main(){
vector<int> v = {1,2,3,5,6,4,7,8,9,10};
sort(v.begin(),v.end());
int n = v.size();
Node *root = makebst(v,0,n-1);
inorder_traversel(root);
cout<<endl;
lca(root, 4,2);




}
