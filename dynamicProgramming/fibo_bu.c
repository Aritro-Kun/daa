//We solve the fibonacci problem, but in the bottom up approach, firt in the form of array.

//Bottom up is about solving from the bottom/the smallest subproblem.

#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    printf("Enter the nth value: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        if(i==0){
            arr[i]=0;
        }
        else if(i==1){
            arr[i]=1;
        }
        else{
            arr[i] = arr[i-1]+arr[i-2];
        }
    }
    printf("The %dth term is %d.", n, arr[n-1]);
    return 0;
}