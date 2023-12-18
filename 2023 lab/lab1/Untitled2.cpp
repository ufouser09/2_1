#include <stdio.h>
#include <stdlib.h>

void sirala(int dizi[], int N) {
    int i;
    int max1 = dizi[0];
    int max2 = dizi[0];
    int max3 = dizi[0];
    int min1 = dizi[0];
    int min2 = dizi[0];
    int min3 = dizi[0];

    for (i = 0; i < N; i++) {
        if (dizi[i] > max3) {
            if (dizi[i] > max2) {
                if (dizi[i] > max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = dizi[i];
                } else {
                    max3 = max2;
                    max2 = dizi[i];
                }
            } else {
                max3 = dizi[i];
            }
        }

        if (dizi[i] <= min3) {
            if (dizi[i] <= min2) {
                if (dizi[i] <= min1) {
                    min3 = min2;
                    min2 = min1;
                    min1 = dizi[i];
                } else {
                    min3 = min2;
                    min2 = dizi[i];
                }
            } else {
                min3 = dizi[i];
            }
        }
    }

    printf("en buyuk 3 ogrencimiz(buyukten kucuge)=%d %d %d\n", max1, max2, max3);
    int toplam1 = max1 + max2 + max3;
    printf("en buyuk sayilarin toplamý=%d\n", toplam1);

    printf("en kucuk 3 öðrencimiz(kucukten buyuge)=%d %d %d\n", min1, min2, min3);
    int toplam2 = min1 + min2 + min3;
    printf("en kucuk sayilarin toplamý=%d\n", toplam2);
}

int main() {
    int N;
    int i;

    do {
        printf("lutfen dizinin boyutunu giriniz\n");
        scanf("%d", &N);
    } while (N < 6);

    int dizi[N];

    printf("lutfen diziyi giriniz\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &dizi[i]);
    }

    sirala(dizi, N);
}
