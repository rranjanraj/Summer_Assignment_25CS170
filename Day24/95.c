//wap to find longest word.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], word[100];
    int i, j = 0, max_len = 0, current_len = 0;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            word[j++] = str[i];
            current_len++;
        } else {
            word[j] = '\0';
            if (current_len > max_len) {
                max_len = current_len;
            }
            j = 0;
            current_len = 0;
        }
    }
    word[j] = '\0';
    if (current_len > max_len) {
        max_len = current_len;
    }

    printf("Length of longest word: %d\n", max_len);
    return 0;
}