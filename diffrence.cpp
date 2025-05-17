#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&v,int k,int left,int right){
    int n = v.size();
   
    
    while(left<=right){
        int mid = left + (right-left)/2;
        if(v[mid]==k){
            return mid;
        }
        else if(v[mid]<k){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}
vector<pair<int,int>> give_pair(vector<int>&v,int k){
    int n = v.size();
    vector<pair<int,int>> ans;
    sort(v.begin(),v.end());
   for(int i = 0;i<n;i++){
    int left = i+1;
    int right = n-1;
    int j = binary_search(v,k+v[i],left,right);
    if(j!=-1){
        ans.push_back({v[i],v[j]});
    }
   }
   return ans;
}


int main(){
    vector<int> v = {5,8,34,2,4,90,45,23,6,9};
    int k = 4;
    vector<pair<int,int>> ans = give_pair(v,k);
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
   
}