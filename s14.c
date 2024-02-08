#include <stdio.h>
#include <stdlib.h>

// 5x5 arrayde yan yana veya üst üste ali yazıp yazmadığının kontrolü
int main() {
    int n,m;
    printf("NxM dizide dikeyde ve yatayda ali aranacak.\nN: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);

    char array[n][m];
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m;j++) {
            printf("[%d][%d]: ", i, j);
            scanf(" %c", &array[i][j]);
        }
    }
    char found = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            // horizontal check
            int my = i, mx = j == 0 ? 1 : j == m-1 ? j-1 : j;
            if ((array[my][mx-1] == 'a' && array[my][mx] == 'l' && array[my][mx+1] == 'i')) {
                found = 1;
                break;
            }
            
            // vertical check
            my = i == 0 ? 1 : i == n-1 ? i-1 : i;
            mx = j;
            if ((array[my-1][mx] == 'a' && array[my][mx] == 'l' && array[my+1][mx] == 'i')) {
                found = 1;
                break;
            }
        }
        if (found == 1) break;
    }
    
    if (found == 1) {
        puts("ali bulundu");
    }

    return 0;
}