#include <bits/stdc++.h>
using namespace std;

// General tree node
typedef struct gnode {
    int data;
    vector<struct gnode*> children;
} Gnode;

// Binary tree node (Left-Child Right-Sibling)
typedef struct bnode {
    int data;
    struct bnode* left;
    struct bnode* right;
} Bnode;

// Conversion from general tree to binary tree (LC-RS)
Bnode* conversion(Gnode* root) {
    if (!root) return NULL;

    Bnode* broot = new Bnode;
    broot->data = root->data;
    broot->left = NULL;
    broot->right = NULL;

    if (root->children.size() == 0)
        return broot;

    broot->left = conversion(root->children[0]);

    Bnode* current = broot->left;
    for (int i = 1; i < root->children.size(); i++) {
        current->right = conversion(root->children[i]);
        current = current->right;
    }

    return broot;
}

// Print binary tree (preorder traversal)
void printBinaryTree(Bnode* root) {
    if (!root) return;
    cout << root->data << " ";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main() {
    // Creating general tree manually:
    //         1
    //       / | \
    //      2  3  4
    //        / \
    //       5   6

    Gnode* root = new Gnode;
    root->data = 1;

    Gnode* node2 = new Gnode;
    node2->data = 2;

    Gnode* node3 = new Gnode;
    node3->data = 3;

    Gnode* node4 = new Gnode;
    node4->data = 4;

    Gnode* node5 = new Gnode;
    node5->data = 5;

    Gnode* node6 = new Gnode;
    node6->data = 6;
    Gnode* node7 = new Gnode;
    node7->data = 7;
    Gnode* node8 = new Gnode;
    node8->data = 8;
    Gnode* node9 = new Gnode;
    node9->data = 9;
    Gnode* node10 = new Gnode;
    node10->data = 10;



    // Connect children
    root->children = {node2, node3, node4,node5};
    node4->children = {node6, node7};
    node5->children = {node8};
    node7->children = {node9,node10};

    // Convert to binary tree
    Bnode* binaryRoot = conversion(root);

    // Print converted binary tree
    cout << "Preorder of Binary Tree (LC-RS representation): ";
    printBinaryTree(binaryRoot);
    cout << endl;

    return 0;
}
