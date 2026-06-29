#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum capacity of the array

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Tracks the current number of elements in the array
    int choice, element, position, i, found;

    while (1) {
          
        printf("\n1. Create/Initialize Array");
        printf("\n2. Display Array Elements");
        printf("\n3. Insert an Element");
        printf("\n4. Delete an Element");
        printf("\n5. Search for an Element");
        printf("\n6. Exit");
        
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("\nExiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Create/Initialize Array
                printf("Enter the number of elements to insert (Max %d): ", MAX_SIZE);
                scanf("%d", &size);

                if (size < 0 || size > MAX_SIZE) {
                    printf("\nError: Invalid size! Resetting size to 0.\n");
                    size = 0;
                } else {
                    printf("Enter %d elements:\n", size);
                    for (i = 0; i < size; i++) {
                        printf("Element %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                    printf("\nArray initialized successfully!\n");
                }
                break;

            case 2: // Display Array Elements
                if (size == 0) {
                    printf("\nArray is empty! Nothing to display.\n");
                } else {
                    printf("\nArray elements are: [ ");
                    for (i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("]\nCurrent size: %d\n", size);
                }
                break;

            case 3: // Insert an Element
                if (size >= MAX_SIZE) {
                    printf("\nError: Array Overflow! Cannot insert more elements.\n");
                    break;
                }

                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter position (1 to %d): ", size + 1);
                scanf("%d", &position);

                // Convert 1-based position to 0-based array index
                if (position < 1 || position > size + 1) {
                    printf("\nError: Invalid position!\n");
                } else {
                    // Shift elements to the right to make room
                    for (i = size; i >= position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position - 1] = element; // Insert the element
                    size++; // Increase array count
                    printf("\nElement inserted successfully!\n");
                }
                break;

            case 4: // Delete an Element
                if (size == 0) {
                    printf("\nError: Array Underflow! No elements to delete.\n");
                    break;
                }

                printf("Enter position to delete (1 to %d): ", size);
                scanf("%d", &position);

                if (position < 1 || position > size) {
                    printf("\nError: Invalid position!\n");
                } else {
                    element = arr[position - 1]; // Save element to show the user
                    // Shift elements to the left to close the gap
                    for (i = position - 1; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--; // Decrease array count
                    printf("\nElement %d deleted successfully from position %d!\n", element, position);
                }
                break;

            case 5: // Search for an Element (Linear Search)
                if (size == 0) {
                    printf("\nArray is empty! Nothing to search.\n");
                    break;
                }

                printf("Enter the element to search for: ");
                scanf("%d", &element);
                
                found = -1;
                for (i = 0; i < size; i++) {
                    if (arr[i] == element) {
                        found = i;
                        break; // Stop at the first match
                    }
                }

                if (found != -1) {
                    printf("\nElement %d found at index %d (Position %d).\n", element, found, found + 1);
                } else {
                    printf("\nElement %d not found in the array.\n", element);
                }
                break;

            default:
                printf("\nError: Invalid choice! Please select a valid option (1-6).\n");
        }
    }

    return 0;
}
