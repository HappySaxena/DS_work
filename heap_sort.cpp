#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[],int n,int i){
    int smallest = i;
    int left = (2*i)+1;
    int right = (2*i)+2;

    if(left<n && arr[left]<arr[smallest])
        smallest = left;
    
    if(right<n && arr[right]< arr[smallest])
    smallest = right;

    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
    // for( int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<< endl;
return;
}
void heapsort(int arr[],int n){
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i= n-1;i> 0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

int main(){
    int arr[] = {
        12,45,10,34,67,23,2,7,45};
        int n = sizeof(arr)/sizeof(arr[0]);
        heapsort(arr,n);
        for(int i =0;i<n;i++){
            cout<<arr[i]<< " ";
        }
    
}