#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 50
#define NAME_LENGTH 50
#define DEPT_LENGTH 30

// Structure to define Employee attributes
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char department[DEPT_LENGTH];
    float basicSalary;
} Employee;

// Helper function to clear leftover characters in input streams
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Employee staff[MAX_EMPLOYEES];
    int count = 0;
    int choice, i, targetId, found;
    char searchDept[DEPT_LENGTH];
    float totalPayout, taxAmount, netSalary;

    while (1) {
        
        printf("\n1. Add New Employee Record");
        printf("\n2. Display All Employee Profiles");
        printf("\n3. Search Employee by ID");
        printf("\n4. Filter Employees by Department");
        printf("\n5. Calculate Company Payroll Summary");
        printf("\n6. Exit");
        
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline trail

        if (choice == 6) {
            printf("\nExiting employee database. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Add New Employee Record
                if (count >= MAX_EMPLOYEES) {
                    printf("\nError: System database capacity full!\n");
                    break;
                }

                printf("Enter Employee ID (Unique Integer): ");
                scanf("%d", &staff[count].id);
                clearBuffer();

                // Validate if Employee ID already exists
                found = 0;
                for (i = 0; i < count; i++) {
                    if (staff[i].id == staff[count].id) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("\nError: Employee ID %d already exists!\n", staff[count].id);
                    break;
                }

                printf("Enter Employee Name: ");
                fgets(staff[count].name, NAME_LENGTH, stdin);
                staff[count].name[strcspn(staff[count].name, "\n")] = '\0'; // Strip newline

                printf("Enter Department: ");
                fgets(staff[count].department, DEPT_LENGTH, stdin);
                staff[count].department[strcspn(staff[count].department, "\n")] = '\0'; // Strip newline

                printf("Enter Monthly Basic Salary: ₹");
                scanf("%f", &staff[count].basicSalary);
                clearBuffer();

                if (staff[count].basicSalary < 0.0f) {
                    printf("\nWarning: Negative salary input corrected to 0.\n");
                    staff[count].basicSalary = 0.0f;
                }

                count++;
                printf("\nEmployee profile saved successfully!\n");
                break;

            case 2: // Display All Employee Profiles
                if (count == 0) {
                    printf("\nNo worker files registered on this terminal.\n");
                } else {
                    printf("\n%-6s %-25s %-15s %-12s\n", "ID", "Full Name", "Department", "Basic Salary");
                    printf("----------------------------------------------------------------\n");
                    for (i = 0; i < count; i++) {
                        printf("%-6d %-25s %-15s ₹%-11.2f\n", 
                               staff[i].id, staff[i].name, staff[i].department, staff[i].basicSalary);
                    }
                }
                break;

            case 3: // Search Employee by ID
                if (count == 0) {
                    printf("\nDatabase empty! Nothing to search.\n");
                    break;
                }
                printf("Enter target Employee ID to find: ");
                scanf("%d", &targetId);
                clearBuffer();

                found = -1;
                for (i = 0; i < count; i++) {
                    if (staff[i].id == targetId) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    printf("\n--- Profile Found ---");
                    printf("\nEmployee ID : %d", staff[found].id);
                    printf("\nFull Name   : %s", staff[found].name);
                    printf("\nDepartment  : %s", staff[found].department);
                    printf("\nBasic Salary: ₹%.2f\n", staff[found].basicSalary);
                } else {
                    printf("\nError: Employee ID %d not found.\n", targetId);
                }
                break;

            case 4: // Filter Employees by Department
                if (count == 0) {
                    printf("\nDatabase empty! No groups sorted.\n");
                    break;
                }
                printf("Enter Department name to filter: ");
                fgets(searchDept, DEPT_LENGTH, stdin);
                searchDept[strcspn(searchDept, "\n")] = '\0';

                found = 0;
                for (i = 0; i < count; i++) {
                    if (strcmp(staff[i].department, searchDept) == 0) {
                        if (found == 0) {
                            printf("\nActive records under \"%s\" division:\n", searchDept);
                            printf("%-6s %-25s %-12s\n", "ID", "Full Name", "Basic Salary");
                            printf("-------------------------------------------------\n");
                        }
                        printf("%-6d %-25s ₹%-11.2f\n", staff[i].id, staff[i].name, staff[i].basicSalary);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("\nNo employees found under department \"%s\".\n", searchDept);
                }
                break;

            case 5: // Calculate Company Payroll Summary
                if (count == 0) {
                    printf("\nPayroll cannot execute with 0 total active employees.\n");
                } else {
                    totalPayout = 0;
                    printf("\n================ PAYROLL REPORT ================\n");
                    printf("%-6s %-20s %-12s %-10s %-10s\n", "ID", "Name", "Gross", "Tax(10%)", "Net Pay");
                    printf("------------------------------------------------\n");
                    
                    for (i = 0; i < count; i++) {
                        // Assuming flat 10% structural withholding index calculation metric
                        taxAmount = staff[i].basicSalary * 0.10f;
                        netSalary = staff[i].basicSalary - taxAmount;
                        totalPayout += netSalary;

                        printf("%-6d %-20s ₹%-10.2f ₹%-8.2f ₹%-9.2f\n", 
                               staff[i].id, staff[i].name, staff[i].basicSalary, taxAmount, netSalary);
                    }
                    printf("------------------------------------------------\n");
                    printf("Total Corporate Net Fund Disbursement: ₹%.2f\n", totalPayout);
                    printf("Average Active Worker Take-Home Pay  : ₹%.2f\n", totalPayout / count);
                }
                break;

            default:
                printf("\nError: Choice unrecognized. Please input values from 1 to 6.\n");
        }
    }

    return 0;
}
