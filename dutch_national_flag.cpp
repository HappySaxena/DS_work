#include<bits/stdc++.h>
using namespace std;

void dutch_nation_flag(vector<int>&v)
{
    int lo = 0;
    int mid = 0;
    int hi = v.size()-1;
    while(mid<=hi){
        if(v[mid] == 0){
            swap(v[lo],v[mid]);
            lo++;
            mid++;
        }
        else if(v[mid] == 1){
            mid++;
        }
        else{
            swap(v[mid],v[hi]);
            hi--;
        }
    }
}

 int main()
 {
    vector<int> v = {0,1,2,0,2,1,1,2,2,0,0,1};
    dutch_nation_flag(v);

for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
} 

 }