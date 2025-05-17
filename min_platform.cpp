#include<bits/stdc++.h>
using namespace std;
int min_platform(vector<int>&arrival, vector<int>&departure){
    vector<pair<int,int>>v;
    int n = v.size();
    for(int i=0;i<n;i++){
        v.push_back({arrival[i],departure[i]});
    }
    int count = 1;
    sort(v.begin(),v.end());
    vector<pair<int,int>>temp;
    temp.push_back(v[0]);
    for(int i = 1;i<v.size();i++){
    
    }

}

int main(){
    vector<int>arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int>departure = {910, 1200, 1120, 1130, 1900, 2000};
}