//Write a program to Create contact management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define FILE_NAME "contacts.txt"

// Define structure to hold contact details
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Function Prototypes
void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();
int loadContacts(Contact contacts[]);
void saveContacts(Contact contacts[], int count);

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    CONTACT MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Contact");
        printf("\n2. View All Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Edit Contact");
        printf("\n5. Delete Contact");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        getchar(); // Clear the trailing newline character

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("\nThank you for using Contact Management System!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to safely read a string including spaces
void readString(char *buffer, int maxLength) {
    fgets(buffer, maxLength, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}

// 1. Add a new contact
void addContact() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);

    if (count >= MAX_CONTACTS) {
        printf("\nError: Contact list is full!\n");
        return;
    }

    Contact newContact;
    printf("\nEnter Name: ");
    readString(newContact.name, sizeof(newContact.name));

    printf("Enter Phone Number: ");
    readString(newContact.phone, sizeof(newContact.phone));

    printf("Enter Email Address: ");
    readString(newContact.email, sizeof(newContact.email));

    contacts[count] = newContact;
    count++;

    saveContacts(contacts, count);
    printf("\nContact added successfully!\n");
}

// 2. View all contacts
void viewContacts() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);

    if (count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\n%-5s %-25s %-20s %-30s", "S.No", "Name", "Phone", "Email");
    printf("\n---------------------------------------------------------------------------------");
    for (int i = 0; i < count; i++) {
        printf("\n%-5d %-25s %-20s %-30s", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    printf("\n---------------------------------------------------------------------------------\n");
}

// 3. Search a contact by name
void searchContact() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);
    char searchName[50];
    int found = 0;

    if (count == 0) {
        printf("\nNo contacts available to search.\n");
        return;
    }

    printf("\nEnter Name to search: ");
    readString(searchName, sizeof(searchName));

    for (int i = 0; i < count; i++) {
        // Case-insensitive comparison can be used here (e.g., strcasecmp on Linux/macOS or stricmp on Windows)
        if (strstr(contacts[i].name, searchName) != NULL) {
            if (!found) {
                printf("\n%-25s %-20s %-30s", "Name", "Phone", "Email");
                printf("\n-----------------------------------------------------------------------------");
            }
            printf("\n%-25s %-20s %-30s", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
        }
    }
    
    if (!found) {
        printf("\nNo contact matching '%s' found.\n", searchName);
    } else {
        printf("\n-----------------------------------------------------------------------------\n");
    }
}

// 4. Edit an existing contact
void editContact() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);
    char searchName[50];
    int foundIndex = -1;

    if (count == 0) {
        printf("\nNo contacts available to edit.\n");
        return;
    }

    printf("\nEnter the exact Name of the contact to edit: ");
    readString(searchName, sizeof(searchName));

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nContact not found.\n");
        return;
    }

    printf("\n--- Editing Contact ---");
    printf("\nCurrent Name: %s (Enter new name or press Enter to keep current): ", contacts[foundIndex].name);
    char temp[50];
    readString(temp, sizeof(temp));
    if (strlen(temp) > 0) strcpy(contacts[foundIndex].name, temp);

    printf("Current Phone: %s (Enter new phone or press Enter to keep current): ", contacts[foundIndex].phone);
    readString(temp, sizeof(temp));
    if (strlen(temp) > 0) strcpy(contacts[foundIndex].phone, temp);

    printf("Current Email: %s (Enter new email or press Enter to keep current): ", contacts[foundIndex].email);
    readString(temp, sizeof(temp));
    if (strlen(temp) > 0) strcpy(contacts[foundIndex].email, temp);

    saveContacts(contacts, count);
    printf("\nContact updated successfully!\n");
}

// 5. Delete a contact
void deleteContact() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);
    char searchName[50];
    int foundIndex = -1;

    if (count == 0) {
        printf("\nNo contacts available to delete.\n");
        return;
    }

    printf("\nEnter the exact Name of the contact to delete: ");
    readString(searchName, sizeof(searchName));

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nContact not found.\n");
        return;
    }

    // Shift all subsequent items back by one index
    for (int i = foundIndex; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    count--;

    saveContacts(contacts, count);
    printf("\nContact deleted successfully!\n");
}

// Helper: Load contacts from text file
int loadContacts(Contact contacts[]) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return 0; // File doesn't exist yet, return 0 contacts
    }

    int count = 0;
    // Read formatted data line-by-line until end of file
    while (count < MAX_CONTACTS && fscanf(file, "%49[^|]|%19[^|]|%49[^\n]\n", 
           contacts[count].name, contacts[count].phone, contacts[count].email) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

// Helper: Save contacts to text file
void saveContacts(Contact contacts[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("\nError saving data to file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s|%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
}
