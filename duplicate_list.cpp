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
bool is_duplicate(Node *root,vector<int> v,int i){
  
    if(root->data == v[i]){
        cout<< "Duplicate found" << endl;
        return true;
    }
    if(root->data < v[i]){
        if(root->right == NULL){
            root->right = create_node(v[i]);
            
        }
        else{
            return is_duplicate(root->right,i);
        }
    }
    else if(root->data > v[i]){
        if(root->left == NULL){
            root->left = create_node(v[i]);
            return false;
        }
        else{
            return is_duplicate(root->left,i);
        }
    }
    else if(x < root->data){
        return is_duplicate(root->left,x);
    }
    else{
        return is_duplicate(root->right,x);
    }
}
int main(){
    int n ;
    cin >> n ;
    vector<int> v = {
            1,3,4,5,5,7,8,9,10,10,11,12,13,14,15,16,17,18,19
    };
    Node *root = NULL ;
   root = create_node(v[0]);

   for(int i = 1;i<20;i++){
    if(v[i] == root->data){
        cout << "Duplicate found" << endl;
        break;
    }
    else{
        Node *temp = root ;
        while(temp != NULL){
            if(v[i] < temp->data){
                if(temp->left == NULL){
                    temp->left = create_node(v[i]);
                    break;
                }
                else{
                    temp = temp->left ;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = create_node(v[i]);
                    break;
                }
                else{
                    temp = temp->right ;
                }
            }
        }
    }
   }


}