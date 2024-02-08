#include <stdio.h>
#include <math.h>

void insertionSort(int* array, int n) {
    int temp, j;
    for(int i = 1; i < n; i++)
	{
		temp = array[i];
		j = i - 1;
		while(temp < array[j] && j>=0)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = temp;
	}
}

int getMinNumber(int* digits, int n) {
    int num = 0, multiplier = 0;
    for (int i = n-1; i>-1; i--) {
        num += pow(10, multiplier++) * digits[i];
    }
    return num;
}

int getMaxNumber(int* digits, int n) {
    int num = 0;
    for (int i = 0; i<n; i++) {
        num += pow(10, i) * digits[i];
    }
    return num;
}

// girilen rakamlarla rakamları farklı max ve min sayıları yazdırın
int main() {
    int n;
    printf("Enter the digit count N: ");
    scanf("%d", &n);

    int digits[n];
    for (int i = 0; i<n; i++) {
        printf("[%d]: ");
        scanf("%d", &digits[i]);
    }
    // digits readed
    insertionSort(digits, n);

    printf("Min: %d, Max: %d", getMinNumber(digits, n), getMaxNumber(digits, n));
     

    return 0;
}