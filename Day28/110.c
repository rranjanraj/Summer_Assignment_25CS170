//Write a program to Create bank account system.
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to store account details
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account bank[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function to create a new account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nBank database is full! Cannot create more accounts.\n");
        return;
    }

    Account newAcc;
    printf("\nEnter Account Number: ");
    scanf("%d", &newAcc.accountNumber);

    // Check if account number already exists
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == newAcc.accountNumber) {
            printf("Error: Account number already exists!\n");
            return;
        }
    }

    printf("Enter Account Holder Name: ");
    getchar(); // Clear input buffer
    fgets(newAcc.name, sizeof(newAcc.name), stdin);
    newAcc.name[strcspn(newAcc.name, "\n")] = 0; // Remove newline character

    printf("Enter Initial Deposit: $");
    scanf("%f", &newAcc.balance);

    if (newAcc.balance < 0) {
        printf("Error: Initial deposit cannot be negative!\n");
        return;
    }

    bank[totalAccounts] = newAcc;
    totalAccounts++;
    printf("Account created successfully!\n");
}

// Function to find account index by account number
int findAccount(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            return i;
        }
    }
    return -1;
}

// Function to deposit money
void depositMoney() {
    int accNum;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccount(accNum);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Deposit Amount: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be positive!\n");
        return;
    }

    bank[index].balance += amount;
    printf("Successfully deposited! New Balance: $%.2f\n", bank[index].balance);
}

// Function to withdraw money
void withdrawMoney() {
    int accNum;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccount(accNum);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Withdrawal Amount: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive!\n");
        return;
    }

    if (amount > bank[index].balance) {
        printf("Error: Insufficient balance! Current Balance: $%.2f\n", bank[index].balance);
        return;
    }

    bank[index].balance -= amount;
    printf("Successfully withdrawn! New Balance: $%.2f\n", bank[index].balance);
}

// Function to check account balance
void checkBalance() {
    int accNum;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    int index = findAccount(accNum);
    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("\n--- Account Details ---");
    printf("\nAccount Number: %d", bank[index].accountNumber);
    printf("\nHolder Name   : %s", bank[index].name);
    printf("\nCurrent Balance: $%.2f\n", bank[index].balance);
}

// Main function to drive the menu system
int main() {
    int choice;

    while (1) {
        printf("\n===== BANK MANAGEMENT SYSTEM =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: printf("\nThank you for using our banking system!\n"); return 0;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
