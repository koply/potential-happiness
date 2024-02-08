#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

void findAngles(float reel, float imaginer) {

    // karşı/komşu
    // imaginer eksen y olduğu için karşısı imaginer
    // reel eksen x olduğu için de payda reel
    float radians = atan(imaginer/reel);

    // radian to angle
    float angles = (180.0*radians)/M_PI;
    
    
    printf("radyan: %f\naci: %f\n", radians, angles);
}

// eslenigi ile carpiyor
float multiplyWithConjugate(float reel, float imaginer) {
    return reel*reel + imaginer*imaginer;
}

void multiplyImaginerNums(float r1, float i1, float r2, float i2) {
    float r = r1*r2 - i1*i2;
    float i = r1*i2 + r2*i1;

    printf("Carpim sonucu: %f + (%f)i\n", r,i);
}

void divisionOfImaginerNums(float r1, float i1, float r2, float i2) {
    float r = r1*r2 - i1* (-i2);
    float i = r1*-i2 + r2*i1;

    float divider = r2*r2 + i2*i2;

    r /= divider;
    i /= divider;

    printf("Bolum sonucu: %f + (%f)i\n", r,i);
}

void sumOfImaginerNums(float r1, float i1, float r2, float i2) {
    printf("Toplam sonucu: %f + (%f)i\n", r1+r2, i1+i2);
}

void subtractionOfImaginerNums(float r1, float i1, float r2, float i2) {
    printf("Cikarma sonucu: %f + (%f)i\n", r1-r2, i1-i2);
} 

int main() {

    printf("Karmasik sayinin r ve i giriniz: ");
    float r,i;
    scanf("%f", &r);
    scanf("%f", &i);

    printf("Kompleks gösterim: %f + (%f)i\n", r,i);
    printf("Eslenik gosterim: %f + (%f)i\n", r,-i);
    printf("Mag: %f\n", sqrt(r*r + i*i));
    findAngles(r, i);
    printf("Eslenik carpim sonuc: %f\n", multiplyWithConjugate(r, i));

    printf("2. Karmasik sayinin r ve i giriniz: ");
    float r2, i2;
    scanf("%f", &r2);
    scanf("%f", &i2);
    multiplyImaginerNums(r, i, r2, i2);
    divisionOfImaginerNums(r, i, r2, i2);
    sumOfImaginerNums(r, i, r2, i2);
    subtractionOfImaginerNums(r, i, r2, i2);

    /* sanal sayılarla işlemler 

        a+bi
        a: reel kısım
        b: sanal kısım (imajiner)

        imajiner eksen -> y
        reel eksen -> x
        grafikteki açıyı da tan ile buluyoruz

        eslenik: imajinerin - ile çarpılmışı
        mag: sqrt(r*r + i*i) // pisagor, magitude

        sanal sayının derecesini bulmak için arctan kullan
        yazılımda bu tarz şeyler bize radyan cinsinden 
        değer verir, derece olması için dönüştürmemiz gerek
        dönüştürmek de zor değil

    */
   
    return 0;
}