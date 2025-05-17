#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void prllno(ll n,ll k,vector<ll>& a,vector<ll>& b){
ll sum = -1;
    for(ll i =0;i<n;i++){
        if(b[i]!=(-1)){
            // sum = a[i] + b[i];
            if(sum!=(-1)&& a[i] + b[i] != sum){
                cout << "0" << endl;
                return;
            }
            else{
                sum = a[i] + b[i];
            }
        }
       
       }
       if(sum == -1){
        ll r = k+2 - *max_element(a.begin(),a.end());
       cout<< r << endl;
         return;
     }
     else{
        for(ll i =0;i<n;i++){
            if(sum-a[i]>k || sum<a[i]){
                cout<<"0" << endl;
                return;
            }
        }
        cout<<"1"<< endl;
            
     
     }
        }




int main(){
    ll n;
    cin>> n;
    for(ll i =0;i<n;i++){
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        ll x = p.first;
        ll y = p.second;
        vector<ll>a;
        vector<ll>b;
        
        for(ll j = 0;j<x;j++){
            ll t;
            cin >> t;
            a.push_back(t);
        }
        for(ll j = 0;j<x;j++){
            ll t;
            cin >> t;
            b.push_back(t);
        }
        prllno(x,y,a,b);
    }
}