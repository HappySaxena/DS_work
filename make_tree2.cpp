#include<bits/stdc++.h>
using namespace std ;
typedef struct node{
    int data ;
    node *left = NULL;
    node *right = NULL;
}Node ;

Node* create_node(int x){
    Node *new_node = new Node();
    if(new_node == NULL){
        cout << "Memory allocation failed" << endl;
        exit(1);
    }
    new_node->data = x ;
    return new_node ;
}

Node* make_tree(vector<int>& postorder, vector<int>& inorder, int l_post, int r_post, int l_in, int r_in) {
    if (l_post > r_post || l_in > r_in) return nullptr; // Base case

    Node* root = create_node(postorder[r_post]);

    auto it = find(inorder.begin() + l_in, inorder.begin() + r_in + 1, postorder[r_post]);
    int index = distance(inorder.begin(), it);
    int left_subtree_size = index - l_in;

    root->left = make_tree(postorder, inorder, l_post, l_post + left_subtree_size -1, l_in, index - 1);
    root->right = make_tree(postorder, inorder, l_post + left_subtree_size , r_post-1, index + 1, r_in);

    return root;
}

void inorder_traveresel(Node* root) {
    if (root == nullptr) return;
    inorder_traveresel(root->left);
    cout << root->data << " ";
    inorder_traveresel(root->right);
}

int main(){
vector<int> postorder ={
  4,8,5,2,9,10,6,7,3,1
};
vector<int> inorder = {
    4,2,8,5,1,9,6,10,3,7
};
Node *root = NULL;

root = make_tree(postorder,inorder,0,9,0,9);

inorder_traveresel(root);
}

















































































































   