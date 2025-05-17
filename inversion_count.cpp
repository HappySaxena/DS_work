#include<bits/stdc++.h>
using namespace std;

int inversion_count(vector<int>&v, vector<int>&temp, int left, int right){
    int mid, inv_count = 0;
    if(right>left){
        mid = (right+left)/2;
        inv_count+=inversion_count(v,temp,left,mid);
        inv_count+=inversion_count(v,temp,mid+1,right);
        inv_count+=merge(v,temp,left,mid+1,right);
    }
    return inv_count;
}
int main(){
    vector<int> v = {3,7,8,5,2,1,9,5,6,4};
    vector<int> temp(v.size());
    cout<<inversion_count(v,temp,0,v.size()-1);
    return 0;
}