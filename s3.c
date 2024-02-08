#include <stdio.h>

// number of uppercase letters in an array(n)
// solved with dynamic stack array
int main() {
    int n;
    printf("Enter array size, n: ");
    scanf("%d", &n);

    char arr[n+1];
    printf("Enter text: ");
    // fgets for inputs that includes spaces
    // but scanf leaves a blank whitespace the end of 
    // stdin, so we have to bypass it
    getchar(); // that's gonna be read the blank whitespace
    fgets(arr, n+1, stdin);
    
    // 65-A
    // 90-Z
    int count = 0;
    for (int i = 0; i<n; i++) {
        if (arr[i] < 91 && arr[i] > 64) count++;
    }

    printf("Entered text: %s\nCount of uppercase letters: %d", arr, count);

    return 0;
}