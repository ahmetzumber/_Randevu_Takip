/*
 * kutuphanem.h
 * Butun fonksiyonlarimi kullandigim ve kontrollerini yaptigim main dosyasi
 * Odev_2
 * 23.12.2019 odevi yaptigim tarih
 * Ahmet Zumberoglu - ahmet.zumberoglu@stu.fsm.edu.tr
 */
#include <stdio.h>
#include <stdlib.h>
#include "kutuphanem.h"

int main(int argc, char** argv) {

    int menuControl = 1, islemNo = 0, islemNoCtrl = 1;
    char islemNoString[15];

    while (menuControl == 1) {
        printf("--------MENU--------\n");
        printf("1. Randevu Goster\n");
        printf("2. Randevu Ara\n");
        printf("3. Randevu Ekle\n");
        printf("4. Randevu Sil\n");
        printf("5. Cikis\n");

        while (islemNoCtrl == 1) {
            printf("Bir islem seciniz : ");
            scanf("%s", islemNoString);
            printf("\n");
            if (isDecimal(islemNoString) == 1) {
                islemNo = atoi(islemNoString);
                if (islemNo <= 0 || islemNo > 5)
                    printf("GECERLI BIR ISLEM NUMARASI GIRINIZ !!\n");
                else islemNoCtrl++;
            }
        }
        if (islemNo == 1) {
            randevulariYazdir();
            islemNo = 0;
            islemNoCtrl = 1;
        } else if (islemNo == 2) {

            int option = 0;
            char optionCtrl[30];
            int ctrl = 1;
            printf("1.Ada Gore\n");
            printf("2.Gune Gore\n");
            printf("3.Geri Don\n");

            while (ctrl == 1) {
                printf("Bir islem numarasi giriniz : ");
                scanf("%s", optionCtrl);
                printf("\n");
                if (isDecimal(optionCtrl) == 1) {
                    option = atoi(optionCtrl);
                    if (option <= 0 || option > 3)
                        printf("GECERLI BIR ISLEM NUMARASI GIRINIZ !!\n");
                    else ctrl++;
                } else printf("GECERLI BIR ISLEM NUMARASI GIRINIZ !!\n");
            }

            if (option == 1) {
                int adSoyadDonguCtrl = 1;
                char adSoyad[30];
                while (adSoyadDonguCtrl == 1) {
                    printf("Arama yapmak icin Ad ve Soyad giriniz : ");
                    scanf("%*c%[^\n]", adSoyad);
                    if (isDecimal(adSoyad) == 0) {
                        ismeGoreRandevuArama(adSoyad);
                        //  DOSYA ISLEMLERI GELECEK
                        adSoyadDonguCtrl++;
                        //islemNo = 0;
                        islemNoCtrl = 1;
                        break;
                    } else printf("GECERLI BIR ISLEM NUMARASI GIRINIZ !!\n");
                }
            } else if (option == 2) {
                int gunDonguCtrl = 1, gun;
                char gunStrCtrl[15];
                while (gunDonguCtrl == 1) {
                    gun = 0;
                    gunleriYazdir();
                    printf("Arama yapmak icin bir gun numarasi seciniz : ");
                    scanf("%s", gunStrCtrl);
                    printf("\n");
                    if (isDecimal(gunStrCtrl) == 1) {
                        gun = atoi(gunStrCtrl);
                        if (gun >= 1 || gun <= 7) {
                            guneGoreRandevuArama(gun);
                            gunDonguCtrl++;
                            islemNo = 0;
                            islemNoCtrl = 1;
                        }
                    } else printf("GECERLI BIR ISLEM NUMARASI GIRINIZ !!\n\n");
                }
            } else if (option == 3) {
                islemNo = 0;
                islemNoCtrl = 1;
            }


        } else if (islemNo == 3) {

            char hastaAdi[30];
            int gun = 0, saat = 0;
            char gunControl[15];
            char saatControl[15];

            int control = 1, adSoyadCtrl = 1, gunCtrl = 1;
            while (control == 1) {
                // Ad ve Soyad girisindeki karakter kontrolu
                while (adSoyadCtrl == 1) {
                    printf("Ad ve Soyad giriniz : ");
                    scanf("%*c%[^\n]", hastaAdi);
                    printf("\n");
                    if (isDecimal(hastaAdi) == 0)
                        adSoyadCtrl++;
                    else
                        printf("LUTFEN GECERLI BIR AD SOYAD GIRINIZ !!\n");
                }

                // Gun girisindeki karakter kontrolu
                while (gunCtrl == 1) {
                    gunleriYazdir();
                    printf("Gun numarasi giriniz : ");
                    scanf("%s", gunControl);
                    if (isDecimal(gunControl) == 1) {
                        gun = atoi(gunControl);
                        if (gun >= 1 && gun <= 7) {
                            gunCtrl++;
                        } else printf("LUTFEN GECERLI BIR GUN GIRINIZ !!\n");
                    } else printf("LUTFEN GECERLI BIR GUN GIRINIZ !!\n");
                }
                int saatCtrl = 1;
                // Saat girisindeki karakter kontrolu
                while (saatCtrl == 1) {
                    printf("Saat giriniz : ");
                    scanf("%s", saatControl);
                    if (isDecimal(saatControl) == 1) {
                        saat = atoi(saatControl);
                        if (saat >= 1 && saat <= 24) {
                            saatCtrl++;
                        } else printf("LUTFEN GECERLI BIR SAAT GIRINIZ !!\n");
                    } else printf("LUTFEN GECERLI BIR SAAT GIRINIZ !!\n");
                }
                if (randevuGunControl(gun, saat) == 1)
                    randevuOlustur(hastaAdi, gun, saat);
                else
                    printf("\nGirdiginiz randevu tarihi dolu !!\n\n");

                control++;
                islemNo = 0;
                islemNoCtrl = 1;

            }

        }           
         // RANDEVU SILME
        else if (islemNo == 4) {
            int adSoyadDonguCtrl = 1;
            char adSoyad[30];
            while (adSoyadDonguCtrl == 1) {
                printf("Silmek icin ad ve soyad giriniz : ");
                scanf("%*c%[^\n]", adSoyad);
                printf("\n");
                if (isDecimal(adSoyad) == 0) {
                    randevuSil(adSoyad);
                    adSoyadDonguCtrl++;
                    islemNo = 0;
                    islemNoCtrl = 1;
                } else printf("GECERLI BIR ISLEM NUMARASI GIRINIZ !!\n");
            }
        }            // MENU CIKIS
        else if (islemNo == 5) {
            printf("Cikis Yapiliyor...\n");
            menuControl++;
        }

    }

    return 0;
}

