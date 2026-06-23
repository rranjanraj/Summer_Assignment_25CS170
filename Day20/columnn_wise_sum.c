#include <stdio.h>
int main() {
    int m, n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n], colSum[n];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Calculating column-wise sum
    for (j = 0; j < n; j++) {
        colSum[j] = 0; 
        for (i = 0; i < m; i++) {
            colSum[j] += a[i][j];
        }
    }

    printf("Column-wise sums are:\n");
    for (j = 0; j < n; j++) {
        printf("Sum of column %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}