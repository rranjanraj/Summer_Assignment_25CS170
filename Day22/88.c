#include <stdio.h>

void removeSpaces(char *str) {
    int read = 0;
    int write = 0;

    // Loop until the end of the string
    while (str[read] != '\0') {
        // Skip both spaces and the trailing newline character from fgets
        if (str[read] != ' ' && str[read] != '\n') {
            str[write] = str[read];
            write++;
        }
        read++;
    }
    
    // Terminate the string properly
    str[write] = '\0';
}

int main() {
    char text[100]; // Creates a buffer to hold up to 99 characters
    
    printf("Enter a sentence: ");
    
    // Reads a full line of text safely, including spaces
    fgets(text, sizeof(text), stdin);
    
    removeSpaces(text);
    
    printf("Result: %s\n", text);
    
    return 0;
}
