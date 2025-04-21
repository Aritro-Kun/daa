//Will solve the fibonacci but using bottom to top and using variables.

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
        int a=0; int b=1;
        int c;
        for(int i=3; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main(){
    int n;
    printf("Enter the nth value: ");
    scanf("%d", &n);
    int r = fibo(n);
    printf("The %dth term is %d.", n, r);
    return 0;
}