#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next ;
}Node;

Node* createnode(int x){
Node* newnode = new(Node);
newnode->data = x;
newnode->next = NULL;
return newnode;
}

vector<Node*> hash_table(vector<int>v,int n){
    vector<Node*>hash(n,NULL);
    int j = 0;
    for(int i= 0;i<n;i++){
        int d = (v[i]%n);
        Node* nodee = createnode(v[i]);
        if(hash[d] == NULL){
            hash[d] = nodee;
        }
        else{
        hash[d]->next = nodee;
             }
        }

        return hash;
    }



int main(){
    int n;
    cin>>n;
    vector<int> num={
        34,67,47,37,44,94,12,92,52,64
    };
vector<Node*> hash = hash_table(num,n);
for(auto num:hash){
    if(num == NULL){
        cout<< "NULL" << " ";
        cout<<endl;
        continue;
    }
   
    cout<< num->data<<" ";
    if(num->next !=NULL){
        cout<<" "<<num->next->data;
    }
    cout<<endl;
}
}