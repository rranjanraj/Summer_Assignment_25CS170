#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float num1, num2, result; // Changed data types to float

    while (1) {
        
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nExiting the calculator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("\nError: Invalid choice! Please select a valid option (1-5).\n");
            continue; 
        }

        // Input two float numbers
        printf("Enter first number: ");
        scanf("%f", &num1); // Changed specifier to %f for float
        printf("Enter second number: ");
        scanf("%f", &num2); // Changed specifier to %f for float

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\nResult: %f + %f = %f\n", num1, num2, result); // Used %f
                break;
            case 2:
                result = num1 - num2;
                printf("\nResult: %f - %f = %f\n", num1, num2, result); // Used %f
                break;
            case 3:
                result = num1 * num2;
                printf("\nResult: %f * %f = %f\n", num1, num2, result); // Used %f
                break;
            case 4:
                if (num2 == 0.0f) {
                    printf("\nError: Division by zero is undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, result); // Used %f
                }
                break;
            default:
                printf("\nSomething went wrong.\n");
        }
    }

    return 0;
}
