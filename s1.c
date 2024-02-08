#include <stdio.h>
#include <stdlib.h>

// print the array(n) reverse

void static_array() {
	// static array
	int arr[] = {1,2,3,4,5,6,7};

	// printing indexes
	for (int i = (sizeof(arr)/sizeof(int))-1; i>=0; i--) {
		printf("%d, ", arr[i]);
	}
	puts("static end");
}

void dynamic_array() {
	int n = 0, x;
	printf("enter length of the array, n: ");
	scanf("%d", &n);
	int* arr = malloc(sizeof(int)*n);
	// reading data into array
	for (int i = 0; i<n; i++) {
		printf("%d: ", i);
		scanf("%d", &arr[i]);
	}

	for (int i = n-1; i>=0; i--) {
		printf("%d, ", arr[i]);
	}
	puts("dynamic end");
}

int main() {
	puts("static stack array");
	static_array();
	puts("dynamic heap array");
	dynamic_array();
	return 0;
}
