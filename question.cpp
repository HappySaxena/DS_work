#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> meeting(vector<int>start,vector<int>end,int n){
    vector<pair<int,int>>interval;
    for(int i= 0;i<n;i++){
        interval.push_back({start[i],end[i]});
    }
    sort(interval.begin(),interval.end());
    vector<pair<int,int>> result;
    result.push_back(interval[0]);
    for(int i = 1;i<n;i++){
        if(interval[i].first< result[result.size()-1].second && interval[i].first > result[result.size()-1].first){
            if((interval[i].second - interval[i].first) < (result[result.size()-1].second - result[result.size()-1].first)){
                result[result.size()-1].first = interval[i].first;
                result[result.size()-1].second = interval[i].second;
            }
        }
            else if(interval[i].first == result[result.size()-1].second && (interval[i].second - interval[i].first) < (result[result.size()-1].second - result[result.size()-1].first) ){
                result[result.size()-1].second = interval[i].second;
                result[result.size()-1].first = interval[i].first;

            }
           else if (interval[i].first > result[result.size()-1].second){
                result.push_back(interval[i]);
            }
           
        }
    return result;
        
    }
    

int main(){
    vector<int>start = {
        1,3,0,8,8,8
    };
    vector<int>end = {
        10,5,6,12,9,10
    };
   
    vector<pair<int,int>> air = meeting(start,end,6);
    for(auto p:air){
        cout<<"{"<<p.first<<","<< p.second<<"}"<<" ";
       
    }
   
}