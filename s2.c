#include <stdio.h>
#include <stdlib.h>

// sum of the negative numbers in MxN 2d array

void static_array() {
	int arr[3][3] = {{-1,-2,-3}, {-1,-2,-3}, {1,2,3}};
	int total = 0;

	// iteration of the rows
	for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++) {
		// iteration of the columns
		for (int j = 0; j<sizeof(arr[0])/sizeof(int); j++) {
			if (arr[i][j] < 0) total += arr[i][j];
		}
	}

	printf("total: %d\n", total);
	
}

void dynamic_stackarray(int m, int n) {
	int arr[m][n];
	// reading data
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			printf("[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	
	int total = 0;
	for (int i = 0; i<sizeof(arr)/sizeof(arr[0]) /* m */; i++) {
		for (int j = 0; j<sizeof(arr[0])/sizeof(int) /* n */; j++) {
			if (arr[i][j] < 0) total += arr[i][j];
		}
	}
	printf("dynamic_stackarray#total: %d\n", total);
}

void dynamic_heaparray(int m, int n) {
	// arr is firstly points to a pointer,
	// that pointer also points starts of the 2. dimension's 
	// first index, that index points the int value
	// thats the 2d array definition in heap
	int** arr = malloc(m*sizeof(int*));
	for (int i = 0; i<n; i++) {
		*(arr+i) = (int*) malloc(n*sizeof(int));
	}
	// arr -> row_array
	// row_array + 0 -> column_array
	// column_array + 0 -> int value 

	// reading data into 2d array that stores in heap
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			printf("[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	int total = 0;

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (arr[i][j] < 0) total += arr[i][j];
		}
	}

	printf("dynamic_heaparray#total: %d\n", total);
}

void dynamic_array() {
	printf("M: ");	
	int m,n;
	scanf("%d", &m);
	printf("N: ");
	scanf("%d", &n);
	puts("dynamic stack array");
	dynamic_stackarray(m,n);
	puts("dynamic heap array");
	dynamic_heaparray(m,n);
}

int main() {
	puts("static array");
	static_array();
	puts("dynamic array");
	dynamic_array();

}
