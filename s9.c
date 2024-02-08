#include <stdio.h>
#include <stdint.h>

// letter to index
#define indexByLetter(i) ((i<91 && i>64) ? i-65 : ((i<123 && i>96) ? i-97 : i))

// index to letter
#define letterByIndex(i) (i < 26 ? i+65 : i+97)

#define BUFFERSIZE 512

int main() {
    // 25 letters in the alphabet
    // 65-90 A-Z
    // [0-25] -> A-Z 26 indexes
    // 97-122 a-z
    // [26-51] -> a-z 26 indexes
    char text[BUFFERSIZE];
    printf("Enter the text: \n");
    fgets(text, BUFFERSIZE, stdin);
    int letters[52] = {0};

    int letter_index;
    for (int i = 0; i<BUFFERSIZE; i++) {
        if (text[i] == '\0') break;
        letter_index = indexByLetter(text[i]);
        if (letter_index == text[i]) continue;
        printf("text[%d]: %d, letter_index: %d, letters[%d]: %d\n", i, text[i], letter_index, letter_index, letters[letter_index]);
        letters[letter_index]++;
    }

    // indexes
    int imax, imin;
    for (int i = 0; i<52; i++) {
        if (letters[i] > 0 && letters[i] < letters[imin]) {
            imin = i;
        } else if (letters[i] > letters[imax]) {
            imax = i;
        }
    }

    printf("Max char: %c (%d), %d\nMin char: %c (%d), %d", (char)letterByIndex(imax), imax, letters[imax], (char)letterByIndex(imin), imin, letters[imin]);
}