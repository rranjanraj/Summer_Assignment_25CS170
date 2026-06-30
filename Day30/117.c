#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

// Defining the structure to hold student attributes
typedef struct {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
} Student;

// Helper function to clear the standard input buffer stream
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Student records[MAX_STUDENTS];
    int currentCount = 0;
    int choice, i, targetRoll, found;
    char searchName[NAME_LENGTH];
    float totalMarks, averageMarks;

    while (1) {
        
        printf("\n1. Add New Student Record");
        printf("\n2. Display All Student Records");
        printf("\n3. Search Student by Roll Number");
        printf("\n4. Search Student by Name");
        printf("\n5. Calculate Class Average Marks");
        printf("\n6. Exit");
        
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline trail

        if (choice == 6) {
            printf("\nExiting the system database. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Add New Student Record
                if (currentCount >= MAX_STUDENTS) {
                    printf("\nError: System database full! Cannot add more records.\n");
                    break;
                }

                printf("Enter Roll Number (Integer): ");
                scanf("%d", &records[currentCount].rollNumber);
                clearBuffer();

                // Validation to make sure Roll Number is unique
                found = 0;
                for (i = 0; i < currentCount; i++) {
                    if (records[i].rollNumber == records[currentCount].rollNumber) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("\nError: Roll Number %d already exists in the system!\n", records[currentCount].rollNumber);
                    break;
                }

                printf("Enter Student Name: ");
                fgets(records[currentCount].name, NAME_LENGTH, stdin);
                records[currentCount].name[strcspn(records[currentCount].name, "\n")] = '\0'; // Strip newline

                printf("Enter Marks (out of 100): ");
                scanf("%f", &records[currentCount].marks);
                clearBuffer();

                // Basic bounds verification for marks
                if (records[currentCount].marks < 0.0f || records[currentCount].marks > 100.0f) {
                    printf("\nWarning: Out-of-bounds marks entered. Saving anyway.\n");
                }

                currentCount++;
                printf("\nStudent record saved successfully!\n");
                break;

            case 2: // Display All Student Records
                if (currentCount == 0) {
                    printf("\nDatabase empty! No student records found.\n");
                } else {
                    printf("\n%-12s %-30s %-10s\n", "Roll No", "Student Name", "Marks");
                    printf("----------------------------------------------------\n");
                    for (i = 0; i < currentCount; i++) {
                        printf("%-12d %-30s %-10.2f\n", 
                               records[i].rollNumber, records[i].name, records[i].marks);
                    }
                }
                break;

            case 3: // Search Student by Roll Number
                if (currentCount == 0) {
                    printf("\nDatabase empty! Nothing to search.\n");
                    break;
                }
                printf("Enter Roll Number to look up: ");
                scanf("%d", &targetRoll);
                clearBuffer();

                found = -1;
                for (i = 0; i < currentCount; i++) {
                    if (records[i].rollNumber == targetRoll) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    printf("\nRecord Found!");
                    printf("\nRoll Number : %d", records[found].rollNumber);
                    printf("\nName        : %s", records[found].name);
                    printf("\nMarks       : %.2f\n", records[found].marks);
                } else {
                    printf("\nRecord not found for Roll Number %d.\n", targetRoll);
                }
                break;

            case 4: // Search Student by Name
                if (currentCount == 0) {
                    printf("\nDatabase empty! Nothing to search.\n");
                    break;
                }
                printf("Enter Student Name to look up: ");
                fgets(searchName, NAME_LENGTH, stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;
                for (i = 0; i < currentCount; i++) {
                    // Case-sensitive comparison using built-in string arrays matching logic
                    if (strcmp(records[i].name, searchName) == 0) {
                        if (found == 0) {
                            printf("\nMatching Records Found:\n");
                            printf("%-12s %-30s %-10s\n", "Roll No", "Student Name", "Marks");
                            printf("----------------------------------------------------\n");
                        }
                        printf("%-12d %-30s %-10.2f\n", 
                               records[i].rollNumber, records[i].name, records[i].marks);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("\nNo record matching the name \"%s\" found.\n", searchName);
                }
                break;

            case 5: // Calculate Class Average Marks
                if (currentCount == 0) {
                    printf("\nCannot calculate average. Database is empty!\n");
                } else {
                    totalMarks = 0;
                    for (i = 0; i < currentCount; i++) {
                        totalMarks += records[i].marks;
                    }
                    averageMarks = totalMarks / currentCount;
                    printf("\nTotal Students registered: %d", currentCount);
                    printf("\nClass Performance Average: %.2f / 100\n", averageMarks);
                }
                break;

            default:
                printf("\nError: Choice unrecognized. Please input a number from 1 to 6.\n");
        }
    }

    return 0;
}
