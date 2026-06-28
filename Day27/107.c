#include <stdio.h>

// Define a basic structure
struct Employee {
    int id;
    float salary;
};

int main() {
    struct Employee emp; // Create one variable

    // 1. Input initial data
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // 2. Display original data
    printf("\nOriginal Data:\n");
    printf("ID: %d, Salary: %.2f\n", emp.id, emp.salary);

    // 3. Update the data directly
    printf("\nEnter New Salary to Update: ");
    scanf("%f", &emp.salary);

    // 4. Display updated data
    printf("\nUpdated Data:\n");
    printf("ID: %d, New Salary: %.2f\n", emp.id, emp.salary);

    return 0;
}

    
    
    