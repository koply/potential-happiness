#include <stdio.h>
#include <math.h>

// digit finder for a number
int main() {

    int num, index, length;
    for (;;) {
        printf("Enter the number (-1 for exit): ");
        scanf("%d", &num);
        if (num == -1) break;
        printf("Enter the index that you want (right to left): ");
        scanf("%d", &index);

        length = log10(num)+1;
        if (length < index) {
            printf("Number's digit count is less than the entered index. (%d)", length);
        } else {
            printf("The digit that in the %d index: %d\n", index, (num / (int)pow(10, index)) % 10);
        }
    }
    return 0;
}