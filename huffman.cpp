#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    char data;
    int freq;
    Node* left;
    Node* right;
} Node;
Node * creatnode(char data,int frequency){
    Node* node = new Node();
    node->data = data;
    node->freq = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void encoding(string s){
    vector<char> vec(s.begin(), s.end());

    // Sort the vector
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
    vector<Node*> nodes;
    for(int i = 0;i<vec.size();i++){
        Node* node = creatnode(v[i],1);
        
        nodes.push_back(node);
    }
    for(auto i: vec){
        cout << i << " ";
    }
    cout << endl;


}
int main(){
    string s = "eaebaecdea";
    encoding(s);



}