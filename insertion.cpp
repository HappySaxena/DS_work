#include<bits/stdc++.h>
using namespace std;
// int* insert_sort(int*ptr,int n)
// {
   
// int key = 0, j = 0;
// for(int i=1;i<n;i++){
//     key = *(ptr + i);
//     j = i-1;
//     while(j>=0 && *(ptr+j) > key){
//         *(ptr+j+1) = *(ptr+j);
//         j--;
// }
// *(ptr+j+1) = key;

// }
// return ptr;
// }

void insert_sort(vector<int>&v,int n)
{
for (int i = 1;i<n;i++){
    int key = v[i];
    for(int j = i-1;j>=0;j--){
        if(v[j]>key){
            v[j+1] = v[j];
        }
        else{
            v[j+1] = key;
            break;
        }
    }

}
}

int main(){
vector<int> v={0,45,2,60,45,34,10};
int n = v.size();
cout<<n;
insert_sort(v,n);
for(auto num: v){
cout<<num<<" ";
}
}