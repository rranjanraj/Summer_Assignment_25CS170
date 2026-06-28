//wap to create library management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the Book structure
struct Book {
    int id;
    char title[100];
    char author[50];
    int isIssued; // 0 = Available, 1 = Issued
};

// Global array to store library data
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function declarations
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void flushInput();

int main() {
    int choice;

    while (1) {
        printf("\n===================================\n");
        printf("    LIBRARY MANAGEMENT SYSTEM     \n");
        printf("===================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            flushInput();
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("Thank you for using the Library Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please pick a choice between 1 and 6.\n");
        }
    }
    return 0;
}

// Helper function to clean the input buffer
void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a book to the database
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Error: Library storage is full!\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Unique Book ID (Integer): ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid ID format! Operation canceled.\n");
        flushInput();
        return;
    }

    // Check if ID already exists
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("Error: A book with ID %d already exists.\n", newBook.id);
            return;
        }
    }

    flushInput(); // Clear buffer before reading string arrays

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.isIssued = 0; // Default status is available

    library[bookCount] = newBook;
    bookCount++;

    printf("Success: Book added successfully!\n");
}

// Function to display the catalog
void displayBooks() {
    if (bookCount == 0) {
        printf("\nThe library inventory is empty.\n");
        return;
    }

    printf("\n%-10s %-40s %-25s %-12s\n", "Book ID", "Title", "Author", "Status");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-40s %-25s %-12s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isIssued ? "Issued" : "Available");
    }
}

// Function to search for a book
void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books in the library to search from.\n");
        return;
    }

    int searchId;
    printf("\nEnter Book ID to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input format.\n");
        flushInput();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Status: %s\n", library[i].isIssued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book with ID %d not found.\n", searchId);
}

// Function to check out a book
void issueBook() {
    int issueId;
    printf("\nEnter Book ID to issue: ");
    if (scanf("%d", &issueId) != 1) {
        printf("Invalid input format.\n");
        flushInput();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == issueId) {
            if (library[i].isIssued == 1) {
                printf("Sorry, this book is already issued to someone else.\n");
            } else {
                library[i].isIssued = 1;
                printf("Success: Book '%s' has been issued successfully!\n", library[i].title);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", issueId);
}

// Function to check in a book
void returnBook() {
    int returnId;
    printf("\nEnter Book ID to return: ");
    if (scanf("%d", &returnId) != 1) {
        printf("Invalid input format.\n");
        flushInput();
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == returnId) {
            if (library[i].isIssued == 0) {
                printf("This book is already sitting in the library inventory.\n");
            } else {
                library[i].isIssued = 0;
                printf("Success: Book '%s' has been returned successfully!\n", library[i].title);
            }
            return;
        }
    }
    printf("Book with ID %d does not belong to this library.\n", returnId);
}
