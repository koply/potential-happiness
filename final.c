#include <stdio.h>

// soru 4-)Girilen bir negatif ve pozitif sayı arasındaki sayıların pozitif,negatif ve tek,çift durumunu yazan uygulama.
void question4() {

    int min, max;
    printf("Negatif olan sayiyi girin: ");
    scanf("%d", &min);
    printf("Pozitif olan sayiyi girin: ");
    scanf("%d", &max);

    for (int i = min; i<max; i++) {
        char* tekCift = i % 2 == 0 ? "çift" : "tek";
        char* pozitifNegatif = i < 0 ? "negatif" : "pozitif";
        printf("%d sayisi %s ve %s", i, tekCift, pozitifNegatif);
    }
}

// soru 3-)MxN’lik bir dizide 11’in katı olan sayıların toplamını bulan uygulamayı yazınız.
void question3() {
    // dizi örnek amacıyla tanımlı burada, sınavda 'int arr[M][N] = ......;' şeklinde bırakabilirsiniz
    int M = 10, N = 10;
    int arr[M][N] = {{24 ,50 ,48 , 9 ,25 ,29 ,40 ,23 ,31 ,12},
                     {20 ,19 ,54 ,51 ,11 ,43 ,12 ,39 ,22 ,38},
                     {51 ,36 ,24 ,46 ,19 ,36 ,16 ,22 ,15 ,45},
                     {34 ,49 ,15 ,48 ,25 ,27 ,47 ,14 ,38 ,35},
                     {12 ,35 ,17 ,39 ,34 ,47 ,54 ,19 , 9 ,33},
                     {42 ,37 ,30 ,19 ,39 ,51 ,55 ,35 ,54 ,51},
                     {44 ,34 ,35 ,40 ,35 ,38 ,48 ,52 ,17 ,53},
                     {28 ,35 ,43 ,52 ,35 ,22 ,32 ,10 ,49 ,44},
                     {29 ,43 ,53 ,18 , 9 ,30 ,15 ,17 ,33 ,40},
                     {53 ,23 ,11 ,33 ,51 ,20 ,46 ,47 ,40 ,31}};

    int toplam = 0;
    for (int i = 0; i<M; i++) {
        for (int j = 0; j<N; j++) {
            if (arr[i][j] % 11 == 0) toplam += arr[i][j];
        }
    }
    printf("Toplam: %d", toplam);
}

// soru 2-)Devre analizlerinde geliştirilecek bir yazılım için karmaşık sayı structure ı oluşturulacaktır. Bu structure ı oluşturun.(Birinci kutuya).İkinci kutuya ise oluşturduğunuz structure yapısını kullanarak bir karmaşık sayı tanımlayınız ve ilgili parametrelerine değer atayın
struct KarmasikSayi {
    double reel, imaginer;
};

void question2() {
    struct KarmasikSayi a;
    a.reel = 2.0;
    a.imaginer = 3.0;
}

// soru 1-)20 elemanlı bir diziye -12.22 den küçük değerler kaydedilecektir. Bu elemanlar kaydedildikten sonra sayılar en yakın değere yuvarlanacaktır. Bunu gerçekleştiren uygulamayı yazınız. Fonksiyonu dizi parametrelerini pointer kullanarak  gösterin.
// aslında soruda fonksiyona dizinin parametre ile geldiği yazıyordu
// bu soru birden fazla şekilde yorumlanabilir ve yorumuna göre çözülebilir
// bu yüzden kesin bir çözümü olduğunu düşünmüyorum, soruda yazanları karşılayanları
// doğru kabul edeceklerini düşünüyorum

// diziyi pointer olarak alıyoruz, uzunluğunun 20 olduğunu biliyoruz
#include <math.h> // ceil() fonksiyonu için
void question1(float* dizi) {
    double a;
    for (int i = 0; i<20; i++) {
        a = 0;
        do {
            printf("-12.22'den küçük değerler girin: ");
            scanf("%lf", &a);
        } while (a > -12.22);
        // sayı -12.22'den büyük olduğu sürece döngü içerisinde olacak. -12.22'den küçük
        // olursa döngü içerisinde olmayacak bu sayede de istenilen koşulu sağlayan sayılar
        // alabileceğiz. aldığımız sayıyı yukarıya ceil fonksiyonu ile yuvarlarız. yuvarlama fonksiyonları:
        // ceil   | round     | floor
        // yukarı | mantıksal | aşağı

        // dizinin başlangıç noktasından i kadar ileri git ve * ile o adresin değerini belirt
        // sonra da o değere girilen a değerinin yukarı yuvarlanmış halini eşitle
        *(dizi+i) = ceil(a);
    }

}
