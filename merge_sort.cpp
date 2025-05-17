#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v,int mid,int left,int right){

    int i=left,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=right){
        if(v[i]< v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
            }
        }
            while(i<=mid){
                temp.push_back(v[i]);
                i++;
            }
            while(j<=right){
                temp.push_back(v[j]);
                j++;
            }
            for(int k=0;k<temp.size();k++){
                v[k+left]=temp[k];
            }
            return;
}

void merge_sort(vector<int>&v,int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        merge_sort(v,left, mid);
        merge_sort(v,mid+1,right);
        merge(v,mid,left,right);

    }
    return;
}

int main(){
    vector<int> v = {5,8,34,2,4,90,45,23,6};
merge_sort(v,0,8);

for(int i =0;i<v.size();i++){
    cout<<v[i]<<" ";
}
}