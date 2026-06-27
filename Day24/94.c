//wap to compress a string.
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], compressed[100];
    int i, j = 0, count;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }
        compressed[j++] = str[i];
        if (count > 1) {
            char count_str[10];
            sprintf(count_str, "%d", count);
            for (int k = 0; count_str[k] != '\0'; k++) {
                compressed[j++] = count_str[k];
            }
        }
    }
    compressed[j] = '\0';

    printf("Compressed string: %s\n", compressed);
    return 0;
}