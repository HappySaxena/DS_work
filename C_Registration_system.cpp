#include<bits/stdc++.h>
using namespace std ;

void give_prompt(string s,unordered_map<string,int>& m){
    int i = 1;
    if(m.find(s) == m.end()){
        cout<<"OK"<<endl;
        m[s] = 1;
    }
    else{
        int count = m[s];
        string new_s = s+to_string(count);
        m[new_s] = 1;
        m[s]++;
        cout<<new_s<<endl;

    }
}
int main(){
    int n;
    cin>>n;
    unordered_map<string,int> m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        give_prompt(s,m);
    }
}
