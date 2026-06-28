//wap to create quiz application.
#include <stdio.h>
int main() {
    char answer;
    int score = 0;

    printf("Welcome to the Quiz!\n");

    printf("Question 1: What is the capital of china? (a) London (b) Berlin (c) Paris (d) Beijing\n");
    printf("Your answer: ");
    scanf(" %c", &answer);

    if (answer == 'd') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }

    printf("Question 2: Who is cheif mister of Delhi? (a) Rekha Gupta (b) Shivraj singh chauhan (c) Eknath shinde (d) Arvind kejriwal\n");
    printf("Your answer: ");
    scanf(" %c", &answer);

    if (answer == 'a') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }

    printf("Your final score is: %d/2\n", score);
    return 0;
}