#include<bits/stdc++.h>
using namespace std;

vector<string> compress(vector<int>&vec){
   vector<string> numbers;
   for(int num:vec){
       numbers.push_back(to_string(num));
    }
   vector<string> compressed;
   compressed.push_back(numbers[0]);
   for(int i=1;i<numbers.size();i++){
    if((compressed[0] + numbers[i]) > (numbers[i] + compressed[0]))
    {
        compressed.erase(compressed.begin() + 0);
        compressed.push_back(compressed[0] + numbers[i]);

    }
    else{
        compressed.erase(compressed.begin() + 0);
        compressed.push_back(numbers[i] + compressed[0]);
    }
   }
    return compressed;
}

int main(){
    vector<int> vec = {3,30,34,5,9};
    int n = vec.size();
    vector<string> compressed = compress(vec);
    cout<<compressed[0]<<endl;


}   