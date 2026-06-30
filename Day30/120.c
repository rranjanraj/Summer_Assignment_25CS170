#include <stdio.h>
#include <string.h>

// Global variables for one account
char holderName[50] = "Not Created";
int accountNumber = 0;
float balance = 0.0f;

// Simple function prototypes
void createAccount();
void checkBalance();
void depositMoney();

int main() {
    int choice;

    while (1) {
        // Simple Display Menu
        printf("\n--- EASY BANK SYSTEM ---\n");
        printf("1. Create Account\n");
        printf("2. Check Balance & Details\n");
        printf("3. Deposit Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear the leftover newline character in input buffer
        getchar(); 

        if (choice == 4) {
            printf("\nGoodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                checkBalance();
                break;
            case 3:
                depositMoney();
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to set up the account string and numbers
void createAccount() {
    printf("\nEnter Account Holder Name: ");
    fgets(holderName, sizeof(holderName), stdin);
    holderName[strcspn(holderName, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    printf("Enter Initial Deposit: ₹");
    scanf("%f", &balance);

    printf("\nAccount created successfully!\n");
}

// Function to print details
void checkBalance() {
    printf("\n--- Account Details ---");
    printf("\nName: %s", holderName);
    printf("\nAccount No: %d", accountNumber);
    printf("\nCurrent Balance: ₹%.2f\n", balance);
}

// Function to add money
void depositMoney() {
    float amount;
    printf("\nEnter amount to deposit: ₹");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("\nSuccessfully added ₹%.2f. New Balance: ₹%.2f\n", amount, balance);
    } else {
        printf("\nInvalid amount!\n");
    }
}
