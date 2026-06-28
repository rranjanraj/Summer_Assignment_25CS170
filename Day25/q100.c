//wap to sort words by length.
#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20], temp[20];
    int i, j;

    printf("Enter 5 words:\n");
    for (i = 0; i < 5; i++) {
        gets(words[i]);
    }

    for (i = 0; i < 5 - 1; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("Words in order of increasing length:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}