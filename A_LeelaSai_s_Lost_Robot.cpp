#include<bits/stdc++.h>
using namespace std;
int number( char *s){
    int count = 0;
    int n = strlen(s);
    for(int i = 1;i<=n/2;i++){
        char *p1 = s;
        char *p2 = p1 + 2*i -1;
        while((*p2)!='\0'){
            map<char,int> charcount;
            for(char *p = p1; p <= p2; p++){
                charcount[*p]++;
            }
            if(charcount['L'] == charcount['R'] && charcount['U'] == charcount['D']){
                count++;
                
            }
        p1++;
        p2++;

        }
        
        


        
    }
    return count;
   
    
}

int main(){
    int n;
    cin >> n;
     string s;
    cin >> s;
    char *p = &s[0];
    int count = number(p);
    cout << count << endl;

}