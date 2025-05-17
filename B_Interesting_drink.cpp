#include<bits/stdc++.h>
using namespace std ;
void max_dukan(vector<int>& v,int x){
  
  
   auto it = upper_bound(v.begin(),v.end(),x);
    int count = it - v.begin();
    
  cout<<count<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int tobuy;
    cin>>tobuy;
    for(int i= 0;i<tobuy;i++){
        int x;
        cin>>x;
        max_dukan(v,x);
    }
}