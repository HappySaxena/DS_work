#include<bits/stdc++.h>
using namespace std;

    
    int partition(vector<int>&v,int left,int right){
        int pivot=v[right];
        int idx = left-1;
        for(int i=left;i<right;i++){
            if(v[i]<=pivot){
                idx++;
                int temp = v[idx];
                v[idx] = v[i];
                v[i] = temp;
    }
        }
        idx++;
        int temp = v[idx];
        v[idx] = v[right];
        v[right] = temp;
        
        return idx;
        }
    
    
    void quick_sort(vector<int> &v,int left,int right){
        if(left<right){
            int pivot = partition(v,left,right);
            quick_sort(v,left,pivot-1);
            quick_sort(v,pivot+1,right);
            }
            return;
    }
    
    
    int main(){
    vector<int> v={7,10,4,5,56,56,34,69};
     quick_sort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    }
