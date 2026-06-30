#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

// Structure to define book properties
typedef struct {
    int accessionNumber; // Unique book ID
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int isIssued;        // 0 = Available, 1 = Issued out
} Book;

// Helper function to clear leftover characters in input streams
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice, i, targetId, found;
    char searchAuthor[AUTHOR_LENGTH];

    while (1) {
        
        printf("\n1. Add New Book Record");
        printf("\n2. Display All Books");
        printf("\n3. Search Books by Author");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline trail

        if (choice == 6) {
            printf("\nExiting library database. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Add New Book Record
                if (bookCount >= MAX_BOOKS) {
                    printf("\nError: Library shelf capacity full!\n");
                    break;
                }

                printf("Enter Accession Number (Unique ID): ");
                scanf("%d", &library[bookCount].accessionNumber);
                clearBuffer();

                // Validate if Accession Number already exists
                found = 0;
                for (i = 0; i < bookCount; i++) {
                    if (library[i].accessionNumber == library[bookCount].accessionNumber) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("\nError: Accession Number %d already exists!\n", library[bookCount].accessionNumber);
                    break;
                }

                printf("Enter Book Title: ");
                fgets(library[bookCount].title, TITLE_LENGTH, stdin);
                library[bookCount].title[strcspn(library[bookCount].title, "\n")] = '\0'; // Strip newline

                printf("Enter Author Name: ");
                fgets(library[bookCount].author, AUTHOR_LENGTH, stdin);
                library[bookCount].author[strcspn(library[bookCount].author, "\n")] = '\0'; // Strip newline

                library[bookCount].isIssued = 0; // New books are available by default

                bookCount++;
                printf("\nBook record saved successfully!\n");
                break;

            case 2: // Display All Books
                if (bookCount == 0) {
                    printf("\nLibrary is currently empty! No books to display.\n");
                } else {
                    printf("\n%-10s %-25s %-20s %-12s\n", "Acc. No", "Title", "Author", "Status");
                    printf("----------------------------------------------------------------------\n");
                    for (i = 0; i < bookCount; i++) {
                        printf("%-10d %-25s %-20s %-12s\n", 
                               library[i].accessionNumber, 
                               library[i].title, 
                               library[i].author, 
                               library[i].isIssued ? "Issued" : "Available");
                    }
                }
                break;

            case 3: // Search Books by Author
                if (bookCount == 0) {
                    printf("\nLibrary is empty! Nothing to search.\n");
                    break;
                }
                printf("Enter Author Name to look up: ");
                fgets(searchAuthor, AUTHOR_LENGTH, stdin);
                searchAuthor[strcspn(searchAuthor, "\n")] = '\0';

                found = 0;
                for (i = 0; i < bookCount; i++) {
                    if (strcmp(library[i].author, searchAuthor) == 0) {
                        if (found == 0) {
                            printf("\nBooks found by \"%s\":\n", searchAuthor);
                            printf("%-10s %-25s %-12s\n", "Acc. No", "Title", "Status");
                            printf("---------------------------------------------------\n");
                        }
                        printf("%-10d %-25s %-12s\n", 
                               library[i].accessionNumber, 
                               library[i].title, 
                               library[i].isIssued ? "Issued" : "Available");
                        found = 1;
                    }
                }
                if (!found) {
                    printf("\nNo books found written by author \"%s\".\n", searchAuthor);
                }
                break;

            case 4: // Issue a Book
                if (bookCount == 0) {
                    printf("\nLibrary is empty! No books available to issue.\n");
                    break;
                }
                printf("Enter Book Accession Number to issue: ");
                scanf("%d", &targetId);
                clearBuffer();

                found = 0;
                for (i = 0; i < bookCount; i++) {
                    if (library[i].accessionNumber == targetId) {
                        found = 1;
                        if (library[i].isIssued == 1) {
                            printf("\nSorry, the book \"%s\" is already issued out.\n", library[i].title);
                        } else {
                            library[i].isIssued = 1;
                            printf("\nSuccess! The book \"%s\" has been issued.\n", library[i].title);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("\nError: Accession Number %d not found.\n", targetId);
                }
                break;

            case 5: // Return a Book
                if (bookCount == 0) {
                    printf("\nLibrary database is empty.\n");
                    break;
                }
                printf("Enter Book Accession Number to return: ");
                scanf("%d", &targetId);
                clearBuffer();

                found = 0;
                for (i = 0; i < bookCount; i++) {
                    if (library[i].accessionNumber == targetId) {
                        found = 1;
                        if (library[i].isIssued == 0) {
                            printf("\nConflict: The book \"%s\" is already marked as available on shelves.\n", library[i].title);
                        } else {
                            library[i].isIssued = 0;
                            printf("\nSuccess! The book \"%s\" has been safely returned.\n", library[i].title);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("\nError: Accession Number %d not found.\n", targetId);
                }
                break;

            default:
                printf("\nError: Invalid option! Please enter a number from 1 to 6.\n");
        }
    }

    return 0;
}
