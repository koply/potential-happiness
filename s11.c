#include <stdio.h>

// fabs -> f is float btw
#define fabs(i) (i < 0 ? -(i) : i)

// i think diff is better than fabs?
#define diff(a, b) (a < b ? b-a : a-b)

// ANALYZE THAT SNIPPET
double sqrt(double x) {
    // for 0 and 1, the square roots are themselves
    if (x < 2)
        return x;
 
    // considering the equation values
    double y = x;
    double z = (y + (x / y)) / 2;
 
    // as we want to get upto 5 decimal digits, the absolute
    // difference should not exceed 0.00001
    while (diff(y - z) >= 0.00001) {
        y = z;
        z = (y + (x / y)) / 2;
    }
    return z;
    
}

// find the sqrt of a number without sqrt function
int main() {
    double x = 16.0;
    printf("Sqrt of %lf: %lf", x, sqrt(x));
    return 0;
}