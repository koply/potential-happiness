#include <stdio.h>

// enter MxN array and calculate the diff between minimum 1. and 2. numbers
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

    int min = arr[0][0], oldmin = arr[0][0];
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            if (arr[i][j] < min) {
                if (min < oldmin) {
                    oldmin = min;
                }
                min = arr[i][j];
            }
        }
    }
    // always positive but just for the question's request abs
    int diff = oldmin-min;
    printf("diff: %d", diff < 0 ? -diff : diff);

}