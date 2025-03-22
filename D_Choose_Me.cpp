#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int min_visit(int n,vector<pair<ll,ll>> p)
{
    ll i = 0;
    ll a = 0,b = 0;
    ll count = 1;
    for(i=0;i<n;i++){
        b = b+ p[i].first;
    }
    i = 0;
    while(true){
        a = a + p[i].first + p[i].second;
        b = b - p[i].first;
        
       

      if(a>b){
        break;
      }
        count++;
      
      
      i++;
      

    }
    return count;}
int main(){
    ll n;
    cin>> n;
    vector<pair<ll,ll>> p(n);
    for(ll i=0;i<n;i++){
        
        cin>>p[i].first>>p[i].second;
    }
    sort(p.begin(), p.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b) {
    return (a.first + a.second) > (b.first + b.second);  // Descending order
});

    ll a = min_visit(n,p);
    cout<<a;

}
