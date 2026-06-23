//wap to union of arrays.
#include <stdio.h>
int main() {
    int n1, n2;
    printf("Enter the size of  first array: ");
    scanf("%d", &n1);
    
    int arr1[n1];
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    
    int arr2[n2];
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Create a union of the two arrays
    int union_array[n1 + n2];
    int k = 0;
    
    // Add elements of the first array to the union array
    for (int i = 0; i < n1; i++) {
        union_array[k++] = arr1[i];
    }
    
    // Add unique elements of the second array to the union array
    for (int i = 0; i < n2; i++) {
        int is_unique = 1;
        for (int j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            union_array[k++] = arr2[i];
        }
    }
    
    // Print the union array
    printf("Union of arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", union_array[i]);
    }
    
    return 0;
}