// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<pair<int,int>> p(10);
//     for(int i=0;i<10;i++){
//         p[i].first = i;
//         p[i].second = i+1;
//         cout<<p[i].first<<" "<<p[i].second<<endl;

//     }
    
// }
//  #include <bits/stdc++.h>
// using namespace std;
// string check(int n,vector<int> p){
//   int current,next,next2;
//   int f = 0;
//   for(int i=0;i+2<n;i++){
//     current = p[i];
//     next = p[i+1];
//     next2 = p[i+2];
//     if(next2/next != next/current){
//       f = 1;
//       break;
//     }
//   }
//     if(f==0){
//       return "Yes";
//     }
//       else{
//         return "No";
//       }
    
// }

// int main(){
//   int n;
//   cout<< "give no. of terms : ";
//   cin>> n;
//   int i;
//   vector<int> p(n,8);
//   for(i=0;i<n;i++){
//     cout << "give number: " ;
//     cin>>p[i];
//     cout<< '\n';
//   }
//   string name = check(n,p);
//   cout<<name;
// }
#include <bits/stdc++.h>
using namespace std;
string check(int i,int n,vector <int> p){
    int f =  0;
    int j,temp;
        if(i==n-1){
        return "No";
        }
          cout << p[i]<<' '<<p[i+1]<<'\n';
          temp = p[i];
          p[i] = p[i+1];
          p[i+1] = temp;
        
        cout << p[i]<<' '<<p[i+1];
        for(j=0;j<n-1;j++){
            if(p[j]>p[j+1]){
                f =1 ;
                break;
            }
        }
        if(f==1){

        
        return check(i+1,n,p);
        }
        else{
            return "Yes";
        }
} 

int main(){
    vector<int> p(5);

    
    for (int i=0;i<5;i++){
        cout<< "give number : ";
        cin>>p[i];
        cout<< '\n';

    }
    int i = 0;
    int n = 5;
    string result = check(i,n,p);
    cout << result;  
}