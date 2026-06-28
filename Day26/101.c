//wap to create a number guessing game.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, user_guess, attempts = 0;

    // Use current time as seed for random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    
    printf("     Welcome to the Number Guessing Game!\n");
    
    printf("I have picked a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    // Loop runs until the user guesses the correct number
    do {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        attempts++;

        // Provide feedback based on the user's guess
        if (user_guess > secret_number) {
            printf("Too high! Try a lower number.\n\n");
        } 
        else if (user_guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } 
        else {
            printf("\n CONGRATULATIONS! You got it!\n");
            printf("You guessed the secret number %d in %d attempts.\n", secret_number, attempts);
        }
    } while (user_guess != secret_number);

    return 0;
}
