#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int>&v,int k){\
    int n = v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<k;i++){
        if(v[i]<0){
            v[i] = -v[i];
        }
        else{
            break;
        }
    }
    return accumulate(v.begin(),v.end(),0);
}

int main(){
    vector<int> v = {5,8,0,4,-9,5,3,6};
    int k = 2;
    int sum = max_sum(v,k);
    cout<<sum;
    return 0;
    

}