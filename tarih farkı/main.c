#include <stdio.h>
#include <time.h>

struct TarihSaat {
    int yil;
    int ay;
    int gun;
    int saat;
    int dakika;
    int saniye;
};

union Zaman {
    struct TarihSaat tarihSaat;
    time_t epochZaman;
};

time_t tarihSaatToEpoch(struct TarihSaat ts) {
    struct tm zaman = {0};
    zaman.tm_year = ts.yil - 1900; // Yýl 1900'den itibaren
    zaman.tm_mon = ts.ay - 1;       // Ay 0'dan baþlar
    zaman.tm_mday = ts.gun;
    zaman.tm_hour = ts.saat;
    zaman.tm_min = ts.dakika;
    zaman.tm_sec = ts.saniye;
    
    return mktime(&zaman);
}

int main() {
    union Zaman zaman1, zaman2;
    time_t epoch1, epoch2, fark;

    // Kullanýcýdan tarih ve saat bilgilerini alma
    printf("1. Tarih ve Saat (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &zaman1.tarihSaat.yil, &zaman1.tarihSaat.ay,
                                 &zaman1.tarihSaat.gun, &zaman1.tarihSaat.saat,
                                 &zaman1.tarihSaat.dakika, &zaman1.tarihSaat.saniye);

    printf("2. Tarih ve Saat (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &zaman2.tarihSaat.yil, &zaman2.tarihSaat.ay,
                                 &zaman2.tarihSaat.gun, &zaman2.tarihSaat.saat,
                                 &zaman2.tarihSaat.dakika, &zaman2.tarihSaat.saniye);

    // Tarih saatleri epoch'a çevirme
    epoch1 = tarihSaatToEpoch(zaman1.tarihSaat);
    epoch2 = tarihSaatToEpoch(zaman2.tarihSaat);

    // Zaman farkýný hesaplama
    fark = epoch2 - epoch1;

    // Sonuçlarý ekrana yazdýrma
    printf("1. Tarih ve Saatin Epoch Degeri: %ld\n", epoch1);
    printf("2. Tarih ve Saatin Epoch Degeri: %ld\n", epoch2);
    printf("iki tarih arasindaki zaman farki (saniye): %ld\n", fark);

    return 0;
}

