#include<stdio.h>
int main(){
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Calculate the length of the string
    while (str[length] != '\0') {
        length++;
    }

    printf("Original string is: %s", str);

    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }

    printf("Reversed string is: %s", str);

    return 0;
}