#include <stdio.h>

// Function prototype
unsigned long long fibonacci(int n);

int main() {
    int num;
    printf("Enter a position number: ");
    
    if (scanf("%d", &num) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    
    if (num < 0) {
        printf("Position cannot be negative\n");
    } else {
        printf("Fibonacci number at position %d is %llu\n", num, fibonacci(num));
    }
    
    return 0;
}


unsigned long long fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}
