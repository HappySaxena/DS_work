#include <stdio.h>
#include <stdlib.h>
int multi(int a,int b){
    if(b==1){
        return a;
    }
    else{
        return a+ multi(a,b-1);
    }
}
int main(){
    int x = multi(4,4);
    printf("%d\n",x);
}