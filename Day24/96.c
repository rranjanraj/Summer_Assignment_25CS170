//wap to remove duplicate characters.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], unique[100];
    int i, j, k = 0;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; j < k; j++) {
            if (str[i] == unique[j]) {
                break;
            }
        }
        if (j == k) {
            unique[k++] = str[i];
        }
    }
    unique[k] = '\0';

    printf("String after removing duplicates: %s\n", unique);
    return 0;
}