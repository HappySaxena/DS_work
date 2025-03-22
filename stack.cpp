#include <bits/stdc++.h>
using namespace std;
void checking(string s){
    int i=0,j=0,k=0,m=0,c = 0;
    while(s[j]!='\0'){
        if(s[j]=='('){
            i=i+1;
           
        }
        if(s[j]==')'){
            i--;
            if(i<0){
                break;
            }
        }
        if(s[j]=='{'){
            k=k+1;
            
        }
        if(s[j]=='}'){
            k--;
            if(k<0){
                break;
            }
        }
        if(s[j]=='['){
            m=m+1;
            
        }
        if(s[j]==']'){
            m--;
            if(m<0){
                break;
            }
        }
        j++;
    }
        if(i==0 && k==0 && m==0){
            cout<<"The expression is balanced"<<endl;
        }
        else{
            cout<<"The expression is not balanced"<<endl;
        }
      
    }

int main(){
    string expression ;
    cout<<"Enter the expression : ";
    cin>>expression;
    cout<<"The expression is : "<<expression<<endl;
    checking(expression);


}