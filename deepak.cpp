#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin>>n;
    pair<ll,ll> arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    int count1=0,count2=0; 
    for(ll i=0;i<n;i++){
        count1+=arr[i].first;
    }
    for(ll i=0;i<n;i++){
        ll temp = arr[i].first;
        arr[i].first = 2*arr[i].first+arr[i].second;
        arr[i].second = temp;
    }
    sort(arr,arr+n);
    ll ans=0;
    ll i=n-1;
    while(count1>=count2){
        ans++;
        count2+=arr[i].first-arr[i].second;
        count1-=arr[i].second;
        i--;
    }
    cout<<ans;
}