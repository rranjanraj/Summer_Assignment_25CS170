#include <stdio.h>
int main() {
    int m, n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n], rowSum[m];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Calculating row-wise sum
    for (i = 0; i < m; i++) {
        rowSum[i] = 0; 
        for (j = 0; j < n; j++) {
            rowSum[i] += a[i][j];
        }
    }

    printf("Row-wise sums are:\n");
    for (i = 0; i < m; i++) {
        printf("Sum of row %d: %d\n", i + 1, rowSum[i]);
    }

    return 0;
}