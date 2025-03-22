#include<bits/stdc++.h>
using namespace std;
int* bubble_sort(int *ptr,int n){
    int i=0;
    int j=0;
    char flag = false;
    for(i=0;i<n;i++){
        flag = false;
        for(j=0;j<n-i-1;j++){
            if((*(ptr + j))>(*(ptr+j+1)))
            {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr+1+j);
                *(ptr+1+j) = temp;
                cout<<"changed"<<" ";
                flag = true;
            }
        }
            if(flag == false)
            break;
    

}
return ptr;
}

int main(){
int arr[] = {1,3,4,81,8,10,67,45};
int *ptr = arr;
ptr = bubble_sort(ptr,8);
for(int i=0;i<8;i++){
    cout<<*(ptr+i)<<" ";
    }
}