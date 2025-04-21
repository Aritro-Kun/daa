#include <stdio.h>

int fibo(int n);

int fibo(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

void main(){
    int n;
    printf("Enter the nth value: ");
    scanf("%d", &n);
    int f = fibo(n);
    printf("The %dth term is %d.", n, f);
}