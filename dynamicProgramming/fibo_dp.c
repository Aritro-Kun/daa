#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int fibo(int n, int arr[]);

int fibo(int n, int arr[]){
    if(!(*(arr+n-1)==INT_MAX)){
        return *(arr+n-1);
    }
    int f;
    if(n==1){
        f=0;
    }
    else if(n==2){
        f=1;
    }
    else{
        f = fibo(n-1, arr)+fibo(n-2, arr);
    }
    *(arr+n-1) = f;
    return f;
}

int main(){
    int n;
    printf("Enter the nth term: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        *(arr+i) = INT_MAX;
    }
    int r;
    r = fibo(n, arr);
    printf("The %dth term is %d.", n, r);
    return 0;
}