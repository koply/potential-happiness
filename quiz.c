#include <stdio.h>

/**
    5*5'lik 2d float arraydeki en kucuk 3 elemanın carpımını
    diziyi klavyeden manuel alın
    fonksiyona parametre olarak verin, boyutlarını da verin

    **göz ardı edin. gerçekçi bir çözüm değil.**
*/

// is that a joke for us? its just a quiz question
void quiz(float* arr, int m, int n) {
    float start = *((arr+0*n) + 0);
    float mins[3] = {start, start, start};

    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            if (mins[0] == mins[1]) {
                if (*((arr+i*n) + j) < mins[0]) {
                    mins[0] = *((arr+i*n) + j);
                } else if (*((arr+i*n) + j) > mins[1]) {
                    mins[1] = mins[2] = *((arr+i*n) + j);
                } 
            } else if (mins[1] == mins[2] && *((arr+i*n) + j) > mins[1]){
                mins[2] = *((arr+i*n) + j);
            } else if (*((arr+i*n) + j) < mins[1] && *((arr+i*n) + j) > mins[0]) {
                mins[2] = mins[1];
                mins[1] = *((arr+i*n) + j);
            } else if (*((arr+i*n) + j) > mins[1] && *((arr+i*n) + j) < mins[2]) {
                mins[2] = *((arr+i*n) + j);
            } else if (*((arr+i*n) + j) < mins[0]) {
                mins[2] = mins[1];
                mins[1] = mins[0];
                mins[0] = *((arr+i*n) + j);
            }
            
        }
    }

    printf("Minimum sayilar: %f, %f, %f\n", mins[0], mins[1], mins[2]);
    printf("Carpimlari: %f", (mins[0]*mins[1]*mins[2]));

}

int main() {

    float arr[5][5];
    for (int i = 0; i<5; i++) {
        for (int j = 0; j<5; j++) {
            printf("[%d][%d]: ", i,j);
            scanf("%f", &arr[i][j]);
        }
    }

    quiz((float*)arr, 5,5);


    return 0;
}

