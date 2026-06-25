#include <stdio.h>

int main() {
    char str[100]; // Array to store the user's sentence
    int freq[256] = {0}; // Array to hold counts for all ASCII characters

    printf("Enter a sentence: ");
    // fgets reads the whole line, including spaces, safely
    fgets(str, sizeof(str), stdin); 

    // Loop through the string until the end ('\0')
    for (int i = 0; str[i] != '\0'; i++) {
        // Skip the newline character that fgets automatically adds at the end
        if (str[i] == '\n') {
            continue;
        }
        
        int index = str[i]; // Get ASCII code of the character
        freq[index]++;      // Increase its count
    }

    // Print characters that appeared at least once
    printf("\nCharacter Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            // Make spaces easy to read in the output
            if (i == ' ') {
                printf("' ' : %d\n", freq[i]);
            } else {
                printf("%c : %d\n", i, freq[i]);
            }
        }
    }

    return 0;
}


