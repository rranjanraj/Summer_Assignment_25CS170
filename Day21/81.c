#include<stdio.h>
int main(){
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a string from user input

    // Calculate the length of the string
    while (str[length] != '\0') {
        length++;
    }

    printf("Length of the string is: %d\n", length - 1); // Subtract 1 to exclude the newline character

    return 0;


}