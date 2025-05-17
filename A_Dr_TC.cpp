#include<bits/stdc++.h>
using namespace std;

void print1(string s){
    int n = s.length();
    int sum = 0;
    for(int i=0;i<n;i++){
        string s1 = s;
        if(s1[i] == '1'){
            s1[i] = '0';
        }
        else{
            s1[i] = '1';
        }
        for(int j=0;j<n;j++){
            if(s1[j] == '1'){
                sum ++;
            }
        }
    }
        

        cout<< sum << endl;
        

      
    }
    

int main(){
    int n;
    cin >> n;
  
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        string s(m, '0');
        cin >> s;
        print1(s);
    }
}