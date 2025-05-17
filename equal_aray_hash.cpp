#include<bits/stdc++.h>
using namespace std;

bool areequal(vector<int>&A,vector<int>&B)
{
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]++;
        mp[B[i]]--;
    }
    for(auto it:mp)
    {
        if(it.second!=0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> A = {1,2,3,4,5};
    vector<int> B = {1,2,3,5,5};
    cout<<areequal(A,B);
    return 0;
}