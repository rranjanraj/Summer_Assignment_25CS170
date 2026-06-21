#include <stdio.h>


int isPerfect(int num) {
    if (num <= 1) {
        return 0; // False
    }

    int sum = 0;

    // Loop from 1 up to (num - 1)
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i; // Add divisor to sum
        }
    }

    // Return 1 (True) if sum matches the number, otherwise 0 (False)
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    int number;

    // Take input from the user
    printf("Enter a number to check: ");
    scanf("%d", &number);

    // Call the function and print the result
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}
