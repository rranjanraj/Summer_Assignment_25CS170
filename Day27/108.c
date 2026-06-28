#include <stdio.h>

// Define a simple structure for Marksheet
struct Marksheet {
    int rollNo;
    float math;
    float science;
    float english;
    float total;
    float average;
};

int main() {
    struct Employee; // Creating a structure variable
    struct Marksheet s; 

    // 1. INPUT: Get Student Details and Marks
    printf("=== ENTER STUDENT DETAILS ===\n");
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    
    printf("Enter Maths Marks: ");
    scanf("%f", &s.math);
    
    printf("Enter Science Marks: ");
    scanf("%f", &s.science);
    
    printf("Enter English Marks: ");
    scanf("%f", &s.english);

    // 2. CALCULATION: Total and Average
    s.total = s.math + s.science + s.english;
    s.average = s.total / 3;

    // 3. DISPLAY: Print the Marksheet
    
    printf("          MARKSHEET          \n\n");
    
    printf("Roll Number: %d\n", s.rollNo);
    printf("\n");
    printf("Maths:       %.2f\n", s.math);
    printf("Science:     %.2f\n", s.science);
    printf("English:     %.2f\n", s.english);
    printf("\n");
    printf("Total Marks: %.2f\n", s.total);
    printf("Average:     %.2f%%\n", s.average);
    

    return 0;
}
