#include<bits/stdc++.h>
using namespace std;

int kth_smallest(vector<int>&v, int k)
{
    priority_queue<int> max_heap;
    for(int i=0;i<v.size();i++){
        max_heap.push(v[i]);
        if(max_heap.size()>(k)){
            max_heap.pop();
        }
    }
    
    return max_heap.top();
}
int main()
{ vector<int> v = {
    3,7,8,5,2,1,9,5,6,4
};
int k = 3;
cout<<kth_smallest(v,k);

}