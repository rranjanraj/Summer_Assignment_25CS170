#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIMIT 256

// Function to check if str2 is a rotation of str1
int isRotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths are not equal, they cannot be rotations
    if (len1 != len2 || len1 == 0) {
        return 0;
    }

    // Allocate memory for the concatenated string (len1 * 2 + 1 for null terminator)
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    // Copy str1 into temp and concatenate str1 again
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is a substring of the concatenated string
    int result = 0;
    if (strstr(temp, str2) != NULL) {
        result = 1;
    }

    // Free allocated memory
    free(temp);

    return result;
}

int main() {
    char str1[MAX_LIMIT];
    char str2[MAX_LIMIT];

    // Get first string from user
    printf("Enter the first string: ");
    fgets(str1, MAX_LIMIT, stdin);
    // Remove trailing newline character added by fgets
    str1[strcspn(str1, "\n")] = '\0';

    // Get second string from user
    printf("Enter the second string: ");
    fgets(str2, MAX_LIMIT, stdin);
    // Remove trailing newline character added by fgets
    str2[strcspn(str2, "\n")] = '\0';

    // Check and display the result
    if (isRotation(str1, str2)) {
        printf("\nResult: '%s' is a valid rotation of '%s'\n", str2, str1);
    } else {
        printf("\nResult: '%s' is NOT a rotation of '%s'\n", str2, str1);
    }

    return 0;
}
