//wap to find first repeating character.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i, len;

    printf("Enter a string: ");
    gets(str);
    len = strlen(str);

    // Count frequency of each character
    for (i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    // Find first repeating character
    for (i = 0; i < len; i++) {
        if (freq[str[i]] > 1) {
            printf("First repeating character is: %c\n", str[i]);
            break;
        }
    }

    return 0;
}