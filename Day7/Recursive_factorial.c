#include<stdio.h>
unsigned long long factorial(int n);
 
int main (){
    int num;
    
    printf("Enter a non-negative integer: ");
    
    
    if (scanf("%d", &num) != 1){
        printf("INVALID INPUT\n");
        return 1;
    }
    
    
    if (num < 0){
        printf("Factorial of a negative number is not defined\n");
    }
    else {
        printf("Factorial of %d is %llu\n", num, factorial(num));
    }
    
    return 0;
}

unsigned long long factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}
