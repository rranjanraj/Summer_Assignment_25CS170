//wap to binary search.
#include <stdio.h>
int main() {
    int n, i, key, low, high, mid;
    printf("Enter the size  of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements in sorted order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    low = 0;
    high = n - 1;
    int found = 0; // Flag to indicate if the element is found
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            found = 1; // Element found
            break;
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    
    if (found) {
        printf("Element %d found at index %d.\n", key, mid);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    
    return 0;
}