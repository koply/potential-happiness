#include <stdio.h>

// std -> standard -> varsayılan (asıl, temel, çekirdek) kütüphane
// io -> input/output
// standart input output

// recursive factorial function
int factorial(int n) {
    // koşul ? true ise : false ise
    return n > 0 ? n * factorial(n-1) : 1;
}

int main() {
    // for -> için
    // while -> iken
    int n;
    printf("Factorial(N) -> N: ");
    scanf("%d", &n);
    printf("Factorial(%d): %d", n, factorial(n));

    return 0;
}
