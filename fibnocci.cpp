#include <bits/stdc++.h>
using namespace std;

vector<int> fibnocci_num(int n){
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;
    vector<int> fib_series;
    while(fib<n){
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    fib_series.push_back(fib);
    fib_series.push_back(fib1);
   
    return fib_series;
}

int fib_search(int arr[],int n,int key){
    vector<int> fib = fibnocci_num(n);
    int fib0 = fib[0];
    int fib1 = fib[1];
    int fib2 = fib0 - fib1;
    
    int offset = -1;
    while(fib2>0){
        int i = min(offset + fib2,n-1);
        if(arr[i] == key)
            return i;
        else if(arr[i] < key){
            fib0 = fib1;
            fib1 = fib2;
            fib2 = fib0 - fib1;
            offset = i;
        }
        else{
            fib0 = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib0 - fib1;
        }
    }
        if(fib1>0 && fib2 == 0 && arr[offset+1] == key)
            return offset+1;
    

   
return -1;
}
int main(){
    int arr[] = {1,6,7,10,15,16,19,20,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 23;
    int index = fib_search(arr,n,key);
    if(index != -1)
        cout<<"element found at index "<<index<<endl;
    else
        cout<<"element not found"<<endl;
    return 0;
}