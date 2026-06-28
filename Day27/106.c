#include <stdio.h>

// Define the simple structure
struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    int n;

    printf("How many employees do you want to add? ");
    scanf("%d", &n);

    // Create an array of structures based on user input
    struct Employee emp[n];

    // Input data for each employee
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        
        printf("Enter ID: ");
        scanf("%d", &emp[i].id);
        
        printf("Enter Name (no spaces): ");
        scanf("%s", emp[i].name);
        
        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Display the stored data
    printf("\n--- Employee Records ---\n");
    for(int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }

    return 0;
}
