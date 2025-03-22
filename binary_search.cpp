#include<bits/stdc++.h>
using namespace std;
int interpolation(int arr[],int n,int key){
    int low = 0;
    int high = n-1;
    while(low<=high){
        cout<<"mai chala"<<endl;
        int mid = low + (high-low)/2;
    //  no red hot condition needed here ..as mid is always average of low and high
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main(){
    int arr[] = {1,6,7,10,15,16,19,20,20,20,25,26,31,33,33,37,42,43,45,45,49,49};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    int key = 45;
    int index = interpolation(arr,n,key);
    if(index != -1)
        cout<<"element found at index "<<index<<endl;
    else
        cout<<"element not found"<<endl;

}