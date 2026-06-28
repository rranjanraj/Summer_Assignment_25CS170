//Write a program to Create ticket booking system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10
#define TICKET_PRICE 250

void displaySeats(int seats[ROWS][COLS]);
void bookTicket(int seats[ROWS][COLS]);
void saveBooking(int row, int col);
void loadBookings(int seats[ROWS][COLS]);

int main() {
    int seats[ROWS][COLS] = {0}; 
    int choice;

    loadBookings(seats);

    while(1) {
        printf("\n--- CINEMA TICKET BOOKING SYSTEM ---\n");
        printf("1. View Seat Layout\n");
        printf("2. Book a Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch(choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookTicket(seats);
                break;
            case 3:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displaySeats(int seats[ROWS][COLS]) {
    printf("\n      --- SCREEN THIS WAY ---\n\n");
    printf("    ");
    for(int j = 0; j < COLS; j++) {
        printf("[%d] ", j + 1);
    }
    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        printf("Row %d ", i + 1);
        for(int j = 0; j < COLS; j++) {
            if(seats[i][j] == 0) {
                printf("[ ] "); // Empty seat
            } else {
                printf("[X] "); // Booked seat
            }
        }
        printf("\n");
    }
    printf("\n[ ] = Available  [X] = Booked\n");
}

void bookTicket(int seats[ROWS][COLS]) {
    int row, col;

    printf("\nEnter Row number (1-%d): ", ROWS);
    scanf("%d", &row);
    printf("Enter Seat number (1-%d): ", COLS);
    scanf("%d", &col);

    // Convert to 0-indexed array indices
    int r = row - 1;
    int c = col - 1;

    if(r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Error: Invalid row or seat number!\n");
        return;
    }

    if(seats[r][c] == 1) {
        printf("Error: Seat Row %d, Seat %d is already booked!\n", row, col);
    } else {
        seats[r][c] = 1;
        saveBooking(r, c);
        printf("\nBooking Successful!\n");
        printf("Seat: Row %d, Position %d\n", row, col);
        printf("Total Amount Paid: ₹%d\n", TICKET_PRICE);
    }
}

void saveBooking(int row, int col) {
    FILE *file = fopen("bookings.txt", "a");
    if(file == NULL) {
        printf("Error opening database file to save.\n");
        return;
    }
    fprintf(file, "%d %d\n", row, col);
    fclose(file);
}

void loadBookings(int seats[ROWS][COLS]) {
    FILE *file = fopen("bookings.txt", "r");
    if(file == NULL) {
        // File doesn't exist yet, which is fine for first run
        return;
    }
    int row, col;
    while(fscanf(file, "%d %d", &row, &col) == 2) {
        if(row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            seats[row][col] = 1;
        }
    }
    fclose(file);
}
