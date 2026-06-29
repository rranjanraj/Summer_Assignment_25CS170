#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Flushes the input stream to prevent menu skipped prompts
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char str1[MAX_SIZE] = "";
    char str2[MAX_SIZE] = "";
    char temp[MAX_SIZE] = "";
    int choice, i, len, cmp;

    // Force the user to enter the initial string immediately upon launch
    printf("=================================\n");
    printf("    STRING OPERATIONS SYSTEM     \n");
    printf("=================================\n");
    printf("Please enter your primary string: ");
    fgets(str1, MAX_SIZE, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Strips trailing newline character

    while (1) {
        // Displaying the interactive options menu
        printf("\n---------------------------------");
        printf("\nCURRENT STRING: \"%s\"", str1);
        printf("\n---------------------------------");
        printf("\n1. Change Primary String");
        printf("\n2. View String Length");
        printf("\n3. Copy String to Buffer");
        printf("\n4. Append (Concatenate) New String");
        printf("\n5. Compare with New String");
        printf("\n6. Reverse the String");
        printf("\n7. Exit");
        printf("\n---------------------------------");
        printf("\nEnter choice (1-7): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear input trail 

        if (choice == 7) {
            printf("\nExiting system operations. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: // Change Primary String
                printf("Enter your new primary string: ");
                fgets(str1, MAX_SIZE, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("\nSuccess: String updated!\n");
                break;

            case 2: // View String Length
                len = strlen(str1);
                printf("\nThe string contains: %d characters.\n", len);
                break;

            case 3: // Copy String to Buffer
                strcpy(temp, str1);
                printf("\nCopied successfully to background storage.\n");
                printf("Stored string element: \"%s\"\n", temp);
                break;

            case 4: // Append New String
                printf("Enter string to append to the end: ");
                fgets(str2, MAX_SIZE, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                // Guarding memory space limits
                if (strlen(str1) + strlen(str2) >= MAX_SIZE) {
                    printf("\nError: Combined string size exceeds allocated bounds!\n");
                } else {
                    strcat(str1, str2);
                    printf("\nSuccess: Strings combined!\n");
                }
                break;

            case 5: // Compare with New String
                printf("Enter target string for comparison: ");
                fgets(str2, MAX_SIZE, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("\nResult: Both strings match perfectly.\n");
                } else if (cmp > 0) {
                    printf("\nResult: Your current string is alphabetically larger.\n");
                } else {
                    printf("\nResult: The new input string is alphabetically larger.\n");
                }
                break;

            case 6: // Reverse the String
                len = strlen(str1);
                // Swapping elements from outside edges moving inward
                for (i = 0; i < len / 2; i++) {
                    char t = str1[i];
                    str1[i] = str1[len - 1 - i];
                    str1[len - 1 - i] = t;
                }
                printf("\nSuccess: String characters inverted!\n");
                break;

            default:
                printf("\nError: Choice unrecognized. Try options 1 to 7.\n");
        }
    }

    return 0;
}
