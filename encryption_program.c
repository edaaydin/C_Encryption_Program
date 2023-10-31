#include <stdio.h>

int main() {
    int sayi;

    printf("------------------------------------------------------ \n");
    printf("*******SİFRELEME PROGRAMİ******* \n");
    printf("------------------------------------------------------ \n");

    while(1) {
        // 5 basamakli sayi girmemizi istiyor.
        printf("Lutfen 5 basamakli bir sayi giriniz: ");

        int input_status = scanf("%d", &sayi);
        if (input_status != 1) {

            //Girdi başarili mi diye kontrol ediyor.
            printf("Gecersiz giris. Lutfen sadece sayi giriniz.\n");

            // Sonsuz bir donguden kacinmak icin giris ara bellegini temizliyor.
            while (getchar() != '\n') { }
            continue;
        }
        // Eger sayi 10000 ve 99999 arasinda mi diye kontrol ediyor ve basariliysa kod devam ediyor.
        if (sayi >= 10000 && sayi <= 99999) {
            printf("Sayi girisiniz basarili.\n");

            while(1) {
                // Sifreleme yapmak icin secim istiyor.
                printf("Girilen sayiyi sifrelemek icin P ye, cikmak icin E ye basiniz: ");
                char secim;
                scanf(" %c", &secim);

                // P ye basinca sifrelemeye basliyor.
                if (secim == 'P' || secim == 'p') {

                    // Sayi girildikten sonra sifreleme işlemi yapılır.
                    int birinci_basamak = (sayi / 10000 + 9) % 10;  // Birinci basamak sifrelenir.
                    int ikinci_basamak = (sayi / 1000 % 10 + 9) % 10;  // İkinci basamak sifrelenir.
                    int ucuncu_basamak = (sayi / 100 % 10 + 9) % 10;  // Ucuncu basamak sifrelenir.
                    int dorduncu_basamak = (sayi % 100 / 10 + 9) % 10;  // Dorduncu basamak sifrelenir.
                    int besinci_basamak = (sayi % 10 + 9) % 10;  // Besinci basamak sifrelenir.

                    // Basamakları yer degistirerek sifreleme islemi yapilir.
                    int sifreli_sayi = ucuncu_basamak * 10000 + dorduncu_basamak * 1000 + birinci_basamak  * 100 +  ikinci_basamak * 10 + besinci_basamak ;
                    // 36987 girdigimizde 87256 cikmasi gerekiyor.

                    printf("Sifrelenmis sayi: %d\n", sifreli_sayi);
                }
                else if (secim == 'E' || secim == 'e') {
                    printf("Cikis yapildi!");
                    return 0;
                }
                else {
                    printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
                }
            }
        }
        // Yanlis sayi girisi
        else {
            printf("Girdiginiz sayi 5 basamakli degil. Lutfen tekrar deneyin.\n");
        }
    }
}
