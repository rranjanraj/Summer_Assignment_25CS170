//wap to find common elements.
#include <stdio.h>
int main() {
    int n1, n2;
    printf("Enter the size ofthe first array: ");
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
    
    // Find common elements
    int common_array[n1 < n2 ? n1 : n2];
    int k = 0;
    
    // Add common elements to the common array
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                common_array[k++] = arr1[i];
                break;
            }
        }
    }
    
    // Print the common array
    printf("Common elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", common_array[i]);
    }
    
    return 0;
}