#include<bits/stdc++.h>
using namespace std ;
using ll = long long;

void countt(vector<int>& v,int l,int r,int k){
    int count = 0;
    int sum = 0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i] >=l && v[i] <= r && sum + v[i] <= k){
            count++;
            sum += v[i];
        }
    }
   
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int l;
        cin>>l;
        int r;
        cin>>r;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        countt(arr,l,r,k);
    }
}
