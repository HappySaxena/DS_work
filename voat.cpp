#include <bits/stdc++.h>
using namespace std;
int min_visit(int n,vector<pair<int,int>> p)
{
    int i = 0;
    int a = 0,b = 0;
    int count = 1;
    for(i=0;i<n;i++){
        b = b+ p[i].first;
    }
    i = 0;
    while(true){
        a = a + p[i].first + p[i].second;
        b = b - p[i].first;
        
       

      if(a>b){
        break;
      }
        count++;
      
      
      i++;
      

    }
    return count;}
int main(){
    int n;
    cin>> n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
      
        cin>>p[i].first>>p[i].second;
    }
sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    if ((a.first + a.second) == (b.first + b.second)) {
        return a.second > b.second; // Sort by the second value in descending order
    }
    return (a.first + a.second) > (b.first + b.second); // Sort by the sum in descending order
});


    int a = min_visit(n,p);
    cout<<a;

}
