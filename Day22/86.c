//wap to count words in a sentence.
#include<stdio.h>
int main(){
    char str[100];
    int i, wordCount = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Count words in the sentence
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t'){
            wordCount++;
        }
    }

    // If the last character is not a space, increment word count
    if(i > 0 && str[i - 1] != ' ' && str[i - 1] != '\n' && str[i - 1] != '\t'){
        wordCount++;
    }

    printf("Number of words in the sentence: %d\n", wordCount);
    return 0;
}