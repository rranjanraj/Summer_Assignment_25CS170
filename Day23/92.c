//wap to find maximum occuring character.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i, len, max_freq = 0;
    char max_char;

    printf("Enter a string: ");
    gets(str);
    len = strlen(str);

    // Count frequency of each character
    for (i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    // Find maximum frequency and corresponding character
    for (i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = i;
        }
    }

    printf("Maximum occurring character is: %c with frequency %d\n", max_char, max_freq);
    return 0;
}