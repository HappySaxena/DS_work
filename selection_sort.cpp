#include<bits/stdc++.h>
using namespace std;
// int min_funct(int* ptr,int left,int right){
//     cout<<"aaya hu"<<" ";
//    int min = *(ptr+left);
//     int loc = left ;
//     if(left==right){
//         return left;
//     }
//         while(left<=right){
//             if((*(ptr+left))<min){
//                 min = *(ptr+left);
//                 loc = left;
//         }
//         left++;
//     }
//     cout << min << endl;
//         return loc;
// }
// int* select_sort(int*ptr,int n){
    
//     for(int i=0;i<n;i++){
      
//         int loc = min_funct(ptr,i,n-1);
//         if(loc!=i){
//         int temp = *(ptr+i);
//         *(ptr+i) = *(ptr+loc);
//         *(ptr+loc) = temp;
//         }
//     }
// return ptr;

// }
int min_function(vector<int> v,int left)
{cout<<"mai aaaya"<<" ";
    int min = v[left];
    int z = left;      // hot condition agr chhota nhi mila to z = 0 de dega
    for(int i = left;i<v.size();i++){
        if(v[i]<min){
            min = v[i];
          z = i ;
        }
    }
    cout<<v[z]<< " ";
    cout<<endl;
    return z;
}
void selection(vector<int>&v)
{
    for(int i =0;i<v.size();i++){
        int min = min_function(v,i);
      swap(v[min],v[i]);
      for(auto j:v){
        cout<<j<<" ";
      }
      cout<<endl;    }
    return ;
}
int main(){
    vector<int> v = {
        45,23,50,2,54,55,2,80
    };
    selection(v);
    for(int i : v){
        cout << i<<" ";
    }
}
