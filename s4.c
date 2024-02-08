// prizmaların (tipi kullanıcıdan alınacak)
// hacmini ve yanal alanlarını hesaplayan 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TYPECOUNT 4
#define M_PI 3.14159265358979323846

typedef struct {
    float total_surface_area;
    float total_volume;
} values;

values triangular();
values square();
values rectangle();
values sphere();

char* types[TYPECOUNT] = {"triangular", "square", "rectangle", "sphere"};
values (*funcs[TYPECOUNT])(void) = {triangular, square, rectangle, sphere};

int main() {
    
    puts("Current prisma shapes that you can select: ");
    for (int i = 0; i<TYPECOUNT; i++) {
        printf("[%d] %s\n", i, types[i]);
    }
    
    int n;
    printf("Please enter the number [0,%d] of shape: ", TYPECOUNT-1);
    scanf("%d", &n);
    if (n < TYPECOUNT && n > -1) {
        // calls the determined shape function
        values result = funcs[n]();
        printf("Calculation results of the %s\n", types[n]);
        printf("Total surface area: %f\nTotal volume: %f", 
                        result.total_surface_area, result.total_volume);
    } else {
        puts("unknown shape type");
    }
    
    return 0;
}

values triangular() {
    int a,b,c,z;
    printf("Enter the vertices of the triangle. a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    printf("Enter the depth of prism: ");
    scanf("%d", &z);

    // s also means perimeter/2 (semi-perimeter)
    float s = (a+b+c)/2.0;
    // heron's formula
    float triangle_area = sqrt(s*(s-a)*(s-b)*(s-c));

    values results = {
        .total_surface_area = (a*z)+(b*z)+(c*z)+(triangle_area*2),
        .total_volume = triangle_area*z
    };
    
    return results;
}

values square() {
    int n;
    printf("bir kenar uzunlugu: ");
    scanf("%d", &n);
    values results = {
        .total_surface_area = n*n*6,
        .total_volume = n*n*n
    };
    return results;
}

values rectangle() {
    int x,y,z;
    printf("Enter the x, y, z's of the rectangle: ");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    values results = {
        x*y*2+x*z*2+y*z*2, x*y*z
    };

    return results;
}

values sphere() {
    int r;
    printf("Enter the r (not R) of the sphere: "); 
    scanf("%d", &r);
    values results = {
        .total_surface_area = 4.0 * M_PI * r * r,
        .total_volume = 4.0/3.0 * M_PI * r * r * r
    };

    return results;
}