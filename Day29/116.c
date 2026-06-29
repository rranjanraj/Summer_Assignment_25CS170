#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define NAME_LENGTH 30

// Structure to define product items
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Helper function to clear leftover characters in input streams
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice, i, targetId, qtyChange, found;

    while (1) {
        
        printf("\n   INVENTORY MANAGEMENT SYSTEM   ");
        
        printf("\n1. Add New Product");
        printf("\n2. Display Total Inventory");
        printf("\n3. Restock Product (Add Quantity)");
        printf("\n4. Sell Product (Reduce Quantity)");
        printf("\n5. Exit");
        
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        clearBuffer();

        if (choice == 5) {
            printf("\nExiting system database. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Add New Product
                if (itemCount >= MAX_ITEMS) {
                    printf("\nError: Storage capacity full! Cannot add more items.\n");
                    break;
                }

                printf("Enter Product ID (Integer): ");
                scanf("%d", &inventory[itemCount].id);
                clearBuffer();

                // Validate if Product ID already exists
                found = 0;
                for (i = 0; i < itemCount; i++) {
                    if (inventory[i].id == inventory[itemCount].id) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("\nError: Product ID %d already exists!\n", inventory[itemCount].id);
                    break;
                }

                printf("Enter Product Name: ");
                fgets(inventory[itemCount].name, NAME_LENGTH, stdin);
                inventory[itemCount].name[strcspn(inventory[itemCount].name, "\n")] = '\0'; // Strip newline

                printf("Enter Initial Quantity: ");
                scanf("%d", &inventory[itemCount].quantity);
                
                printf("Enter Unit Price: ");
                scanf("%f", &inventory[itemCount].price);
                clearBuffer();

                itemCount++;
                printf("\nProduct added successfully!\n");
                break;

            case 2: // Display Total Inventory
                if (itemCount == 0) {
                    printf("\nInventory empty! No products listed.\n");
                } else {
                    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
                    printf("-----------------------------------------------------\n");
                    for (i = 0; i < itemCount; i++) {
                        printf("%-10d %-20s %-10d ₹%-10.2f\n", 
                               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;

            case 3: // Restock Product
                if (itemCount == 0) {
                    printf("\nInventory empty! Add a product first.\n");
                    break;
                }
                printf("Enter Product ID to restock: ");
                scanf("%d", &targetId);
                
                found = 0;
                for (i = 0; i < itemCount; i++) {
                    if (inventory[i].id == targetId) {
                        printf("Current quantity for %s: %d\n", inventory[i].name, inventory[i].quantity);
                        printf("Enter quantity to add: ");
                        scanf("%d", &qtyChange);
                        
                        if (qtyChange < 0) {
                            printf("\nError: Value cannot be negative!\n");
                        } else {
                            inventory[i].quantity += qtyChange;
                            printf("\nRestock successful! New quantity: %d\n", inventory[i].quantity);
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nError: Product ID %d not found.\n", targetId);
                }
                break;

            case 4: // Sell Product
                if (itemCount == 0) {
                    printf("\nInventory empty! Nothing to sell.\n");
                    break;
                }
                printf("Enter Product ID to sell: ");
                scanf("%d", &targetId);
                
                found = 0;
                for (i = 0; i < itemCount; i++) {
                    if (inventory[i].id == targetId) {
                        printf("Product: %s | Available Stock: %d\n", inventory[i].name, inventory[i].quantity);
                        printf("Enter quantity to sell: ");
                        scanf("%d", &qtyChange);
                        
                        if (qtyChange < 0) {
                            printf("\nError: Sale quantity cannot be negative!\n");
                        } else if (qtyChange > inventory[i].quantity) {
                            printf("\nError: Stock underflow! Not enough units available.\n");
                        } else {
                            inventory[i].quantity -= qtyChange;
                            float totalBill = qtyChange * inventory[i].price;
                            printf("\nSale successful! Dispensed %d units.", qtyChange);
                            printf("\nTotal Bill Amount: ₹%.2f\n", totalBill);
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nError: Product ID %d not found.\n", targetId);
                }
                break;

            default:
                printf("\nError: Invalid choice! Please select 1-5.\n");
        }
    }

    return 0;
}
