#include<bits/stdc++.h>
using namespace std;

void padded_search(int e_arr[],int flag_arr[],int n,int k){
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(e_arr[mid] == k){
            if(flag_arr[mid]==1){
                cout<<"element found at index "<<mid<<endl;
                return;
            }
            else if(mid > 0 && flag_arr[mid-1]==1 && e_arr[mid-1]==k){
                cout<<"element found at index "<<mid-1<<endl;
                return;
            }
            else{
                cout<<"element not found";
                return;
            }
        }
        else if(e_arr[mid] < k)
            left = mid+1;
        else{
            right = mid-1;
        }    
    }

    cout<<"element not found";
    return;
}