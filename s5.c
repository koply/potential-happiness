#include <stdio.h>

// prints the numbers that division with 11 is zero in the MxN array

// manual division part, not used but in case of want, that can be able to use
typedef struct {
    int quotient;
    int remainder;
} division_r;

division_r manual_divide(int dividend, int divisor) {
    int quotient = 0;
    while (dividend >= divisor) {
        quotient++;
        dividend -= divisor;
    }
    division_r result = { quotient, dividend };
    return result;
}

int main() {

    printf("Enter M and N: ");
    int m,n;
    scanf("%d", &m);
    scanf("%d", &n);

    int arr[m][n];
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    // array initializing

    // the solution is below here
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            if (arr[i][j] % 11 == 0) {
                printf("%d, ", arr[i][j]);
            }
        }
    }

    return 0;
}