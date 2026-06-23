
#include <stdio.h>
int main() {
    int n1, n2;
    printf("Enter the size of the first array: ");
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
    
    // Create an intersection of the two arrays
    int intersection_array[n1 < n2 ? n1 : n2];
    int k = 0;
    
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                intersection_array[k++] = arr1[i];
                break;
            }
        }
    }
    
    // Print the intersection array
    printf("Intersection of arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", intersection_array[i]);
    }
    
    return 0;
}