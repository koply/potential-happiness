#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 100

// check the word is a palindrom word or not
int main() {
    printf("Enter a single word for palindrome check\n> ");
    char arr[BUFFERSIZE];
    scanf("%s", arr);
    
    int palindrome = 1;
    int size = strlen(arr);
    for (int i = 0; i<(size/2)+1; i++) {
        if (arr[i] != arr[size-i-1]) {
            palindrome = 0;
            break;
        } 
    }
    
    printf(palindrome ? "It's palindrome!" : "It's not palindrome!");

    return 0;
}