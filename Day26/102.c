#include <stdio.h>

int main() {
    int age;

    // Prompt the user to enter their age

    printf("     VOTING ELIGIBILITY SYSTEM     \n");
    
    printf("Enter your age: ");
    
    // Read the user input
    if (scanf("%d", &age) != 1) {
        printf("\nError: Invalid input! Please enter a valid number.\n");
        return 1;
    }

    // Validate the logic for an impossible age
    if (age <= 0) {
        printf("\nError: Age cannot be zero or negative.\n");
    } 
    // Check if the person meets the minimum voting age requirement (18)
    else if (age >= 18) {
        printf("\nResult: Congratulations! You are ELIGIBLE to vote.\n");
    } 
    else {
        printf("\nResult: You are NOT eligible to vote.\n");
        printf("You need to wait %d more year to cast your vote.\n", 18 - age);
    }

    
    return 0;
}
