#include <stdio.h>

// MxN array to 1D array
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

    int copied[m*n];
    int x = 0;
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            copied[x++] = arr[i][j];
        }
    }

    // done

    return 0;
}