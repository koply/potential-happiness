#include <stdio.h>
#include <math.h>


// standard deviation of an array
// formula: sqrt( (∑(Xi – ų) ^ 2) / N )
// ų: average num of the array
// N: length of the array


int main() {
    int n;
    printf("Standard deviation of an array that size of N: ");
    scanf("%d", &n);

    int array[n];
    float average = 0;

    for (int i = 0; i<n; i++) {
        printf("[%d]: ");
        scanf("%d", &array[i]);
        average += array[i];
    }

    average /= n;
    // array initialized

    float deviation = 0;
    for (int i = 0; i<n; i++) {
        deviation += pow(array[i] - average, 2);
    }

    float square_root = sqrt(deviation / n);
    printf("Standard deviation of the array is: %f", square_root);

    return 0;
}