#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Enter the size of the magic square: ");
    scanf("%d", &n);
    int magic_square[n][n]; // here magic_squate is a double pointer already ..then only u are allowed to access by magic_square[i][j]..if u want to access by pointer then u have to declare like this
     int *p = &magic_square[0][0]; // to access with single pointer
    
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            magic_square[i][j] = 0;
        }
    }
    
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", magic_square[i][j]);
        }
        printf("\n");
    }
    int m = (n-1)/2 ,k = 0;
     magic_square[k][m] = 1;
    for(int j=1;j<(n*n);j++){
        k = k-1;
       if(k<0){
        k = k +n;

       }
       m = m-1;
         if(m<0){
          m = m +n;
    
         }
         if(magic_square[k][m] != 0 || (k<0 && m<0)){
             k = k+1;
             if(k>=n){
                 k = k - n;
             }
             m = m+1;
             if(m>=n){
                 m = m - n;
             }
             k = k+1;
             if(k>=n){
                 k = k - n;
             }
         }
       
         magic_square[k][m] = j+1;

    }


// printf("%d \n",*(p+3));

 for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", magic_square[i][j]);
        }
        printf("\n");
    }
}