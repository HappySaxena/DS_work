#include<bits/stdc++.h>
using namespace std;

int getmax(int arr[],int n){
    int i=0;
    int max = arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
void counting_sort(int arr[],int n,int exp){
    vector<int> output(n);
    int count[10] = {0};
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)% 10]++;
    }
    for(int i =1;i<10;i++){
        count[i]+= count[i-1];
    }
    for(int i = n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }

}
void radix_sort(int arr[],int n){
    int maxval = getmax(arr,n);
    for(int exp = 1;(maxval/exp) > 0;exp*=10){
  counting_sort(arr,n,exp);
    }
}

int main(){
    int arr[] = {
        345,678,100,34
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<< " ";
    }

}