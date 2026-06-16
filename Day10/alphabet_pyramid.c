#include <stdio.h>

int main() {
    int rows = 5; 

    // Outer loop to handle the number of rows
    for (int i = 1; i <= rows; i++) {
        
        // 1. Inner loop to print leading spaces
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        // 2. Inner loop to print characters in ascending order
        for (int j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }

        // 3. Inner loop to print characters in descending order
        for (int j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        
        printf("\n");
    }

    return 0;
}
