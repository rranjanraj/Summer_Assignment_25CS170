#include <stdio.h>

int main() {
    int n;
    int max_prime = -1;

    
    printf("Enter a number: ");
    scanf("%d", &n);

    
    if (n <= 1) {
        printf("Please enter a number greater than 1.\n");
        return 0;
    }

    
    while (n % 2 == 0) {
        max_prime = 2;
        n = n / 2;
    }

    
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            max_prime = i;
            n = n / i;
        }
    }

    
    if (n > 2) {
        max_prime = n;
    }

    
    printf("The largest prime factor is: %d\n", max_prime);

    return 0;
}
