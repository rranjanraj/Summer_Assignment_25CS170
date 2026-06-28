//wap to sort names alphabetically.
#include <stdio.h>
int main() {
    char names[5][20], temp[20];
    int i, j;

    printf("Enter 5 names:\n");
    for (i = 0; i < 5; i++) {
        gets(names[i]);
    }

    for (i = 0; i < 5 - 1; i++) {
        for (j = i + 1; j < 5; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}