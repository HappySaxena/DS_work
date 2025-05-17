#include<bits/stdc++.h>
using namespace std;
typedef struct node{
char data;
    struct node* left;
    struct node* right;
}
Node;
Node* createNode(char x){
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
Node* maketree(string p,stack<Node*> &s)
{
    for(int i = 0;i<(p.length());i++)
   {
    if(p[i] == ')' || p[i] == ']')
        {while(s.top()->data != '(' && s.top()->data != '[')
        { Node * root = nullptr;
            Node* right = s.top();s.pop();
            if(s.top()->data != '(' && s.top()->data != '[')
            {
                 root = s.top();s.pop();
            }else{
                s.pop();
                s.push(right);
                break;
            }
            
            if(s.top()->data != '(' && s.top()->data != '[')
            {
                root->left = s.top();s.pop();
            }else{
                s.pop();
                s.push(root);
                s.push(right);
                break;
            }
                root->right = right;
                s.push(root);
            }
        }
          
   else{ Node* nodee = createNode(p[i]);
    s.push(nodee);
   }
}
    
        cout << s.size() << endl;
    while(s.size()!=1){
        Node* root = nullptr;
        Node* right = s.top();s.pop();
        root = s.top();s.pop();
        root->right = right;
        root->left = s.top();s.pop();
        s.push(root);
    }
if(s.size() == 1)
    return s.top();
else
    return NULL;

}
void preorderr(Node* root)
{
    
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorderr(root->left);
    
    preorderr(root->right);
}
int main()
{
    stack<Node*> s;
    string inorder = "[a+(b-c)]*[(d-e)/(f+g-h)]";
   Node * root = maketree(preorder,s);
   preorderr(root);
    cout << endl;
    

}
