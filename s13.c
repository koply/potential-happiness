#include <stdio.h>

// MxN and KxN array's concate in a new array
int main() {

    int first[][3] = {{1,2,3}, {1,2,3}};
    int second[][3] = {{1,1,1}, {2,2,2}, {3,3,3}};

    // first array's length of the first dimension
    int a = sizeof(first) / sizeof(first[0]);
    // second array's length of the first dimension
    int b = sizeof(second) / sizeof(second[0]);
    
    // second dimension's length. could be equal in all arrays
    int c = sizeof(first[0]) / sizeof(int);

    int last[a+b][c];
    int index;
    for (int i = 0; i<a+b; i++) {
        int* destination = last[i];
        int* source = (i > (a-1)) ? second[i-a] : first[i];
        for (int j = 0; j<c; j++) {
            destination[j] = source[j];
        }
    }

    printf("{");
    for (int i = 0; i<a+b; i++) {
        printf("{");
        for (int j = 0; j<c; j++) {
            printf("%d, ", last[i][j]);
        }
        printf("}, ");
    }
    printf("}");

    return 0;
}