/*
 * kutuphanem.c
 * Butun fonksiyonlarimin bulundugu kaynak C dosyasi
 * Odev_2
 * 23.12.2019 odevi yaptigim tarih
 * Ahmet Zumberoglu - ahmet.zumberoglu@stu.fsm.edu.
 */
#include "kutuphanem.h"
#include <stdio.h>
#include <stdlib.h>
FILE *file;

void gunleriYazdir() {
    printf("1.Pazartesi\n");
    printf("2.Sali\n");
    printf("3.Carsamba\n");
    printf("4.Persembe\n");
    printf("5.Cuma\n");
    printf("6.Cumartesi\n");
    printf("7.Pazar\n\n");
}

void randevuOlustur(char *adi, int gun, int saat) {
    if ((file = fopen("randevular.txt", "a")) == NULL) {
        printf("Dosya Acilamadi !!\n");
    } else {
        fprintf(file, "\n%s,%d,%d", adi, gun, saat);
        fclose(file);
    }
}

void ismeGoreRandevuArama(char *arananAdSoyad) {

    if ((file = fopen("randevular.txt", "r")) == NULL) {
        printf("Dosya Acilamadi !!\n");
    } else {
        int varMi = 0;
        char *tempHastaAdi = (char*) malloc(sizeof (char)*50);
        char *splitHold = (char*) malloc(sizeof (char)*50);
        while (!feof(file)) {
            fgets(tempHastaAdi, 50, file);
            splitHold = split(tempHastaAdi, ',');
            if (compareTo(splitHold, arananAdSoyad) != 0) {
                puts(tempHastaAdi);
                varMi = 1;
                break;
            }
            free(tempHastaAdi);
            free(splitHold);
            splitHold = (char*) malloc(sizeof (char)*50);
            tempHastaAdi = (char*) malloc(sizeof (char)*50);
        }
        if (varMi == 0) {
            printf("\n");
            printf("Bu isimde bir randevu bulunmamaktadir !!\n");
            printf("\n");
        }
        fclose(file);
    }
}

void guneGoreRandevuArama(int arananGun) {

    if ((file = fopen("randevular.txt", "r")) == NULL) {
        printf("Dosya Acilamadi !!\n");
    } else {

        int varMi = 0;
        char *tempHastaAdi = (char*) calloc(50, sizeof (char));
        while (!feof(file)) {
            fgets(tempHastaAdi, 50, file);

            if (findFirstNumber(tempHastaAdi) == arananGun) {
                varMi = 1;
                printf("%s", tempHastaAdi);

            }
            free(tempHastaAdi);
            tempHastaAdi = (char*) calloc(50, sizeof (char));
        }
        if (varMi == 0) {
            printf("\n");
            printf("Bu gunde bir randevu bulunmamaktadir !!\n");
            printf("\n");
        } else {
            printf("\n");
        }
        fclose(file);
    }
}

void randevulariYazdir() {
    if ((file = fopen("randevular.txt", "r+")) == NULL) {
        printf("Dosya Acilamadi !!\n");
    } else {
        printf("-----RANDEVULAR-----\n");
        while (!feof(file))
            printf("%c", fgetc(file));

        printf("\n");
        fclose(file);
    }

}

void randevuSil(char *silinecekAdSoyad) {
    FILE *file2;
    char const *firstFilePath = "randevular.txt";
    char const *secondFilePath = "randevularTemp.txt";

    if ((file = fopen(firstFilePath, "r")) == NULL) {
        printf("Dosya Acilamadi !!\n");
    } else {
        char *splitHold = calloc(50, sizeof (char));
        //---------------SILME ICIN GECICI DOSYA-------------------//
        if ((file2 = fopen(secondFilePath, "w+")) == NULL) {
            printf("DOSYA ACILAMADI !!\n");
        } else {
            char *tempHastaAdi = calloc(50, sizeof (char));
            while(!feof(file)){
                fgets(tempHastaAdi,50,file);
                splitHold = split(tempHastaAdi,',');
                if (compareTo(silinecekAdSoyad,splitHold)) {
                    continue;
                }
                fputs(tempHastaAdi,file2);   
            }
            fclose(file);
            fclose(file2);
            remove(firstFilePath);
            rename("randevularTemp.txt",firstFilePath);
        }
        //------------------------------------------//      
    }
}
int isDecimal(char *str) {
    int length = 0;
    while (*(str + length) != '\0') {
        length++;
    }
    int i, control = 1;
    for (i = 0; i < length; i++) {
        if (*(str + i) < 48 || *(str + i) > 57) {
            control = 0;
        }
    }
    return control;
}

int length(char*str) {
    int i = 0, length = 0;
    while (str[i] != '\0') {
        length++;
        i++;
    }

    return length;
}

char *split(char *str, char ch) {
    int i, counter = 0;
    for (i = 0; i < length(str); ++i) {
        if (str[i] == ch) break;
        else counter++;
    }
    char *splitText = calloc(counter, sizeof (char));
    int j;
    for (j = 0; j < length(str); ++j) {
        if (str[j] == ch) break;
        else splitText[j] = str[j];
    }
    return splitText;
}

int compareTo(char *str1, char *str2) {
    int i;
    for (i = 0; i < length(str2); i++) {
        if (length(str1) != length(str2)) return 0;
        else
            if (str1[i] == str2[i]) return 1;
    }
    return 0;
}

int findFirstNumber(char *text) {
    char *sayi = calloc(1, sizeof (char));
    int temp = 0;
    int i = 0;
    while ((*(text + i)) != '\0') {
        if (isDigit(text[i])) {
            *sayi = (*(text + i));
            break;
        }
        i++;
    }
    temp = atoi(sayi);
    return temp;
}

int isDigit(char str) {
    int ctrl = 0;
    if ((int) str >= 48 && (int) str <= 57)
        ctrl = 1;
    return ctrl;
}

int * findFirstTwoNumber(char *text) {
    char *ilkSayi = calloc(1, sizeof (char));
    char *ikinciSayi = calloc(2, sizeof (char));
    int * holdNumber = calloc(2, sizeof (int));
    int i = 0;
    int counter = 0;
    while ((*(text + i)) != '\0') {
        if (isDigit((*(text + i)))) {
            if (counter == 0) {
                *ilkSayi = (*(text + i));
                counter++;
            } else {
                *ikinciSayi = (*(text + i));
                if ((*(text + i + 1)) != '\0') {
                    *(ikinciSayi + 1) = *(text + i + 1);
                }
            }
        }
        i++;
    }
    *holdNumber = atoi(ilkSayi);
    *(holdNumber + 1) = atoi(ikinciSayi);
    return holdNumber;
}

int randevuGunControl(int gun, int saat) {
    if ((file = fopen("randevular.txt", "r")) == NULL) {
        printf("Dosya Acilamadi !!\n");
    } else {
        int ctrl = 1;
        char *randevuSatir = (char*) malloc(sizeof (char)*50);
        while (!feof(file)) {
            fgets(randevuSatir, 50, file);
            int *gunVeSaat = findFirstTwoNumber(randevuSatir);
            if (gunVeSaat[0] == gun && gunVeSaat[1] == saat) ctrl = 0;
            free(randevuSatir);
            randevuSatir = (char*) malloc(sizeof (char)*50);
        }
        fclose(file);
        if (ctrl == 0) return 0;     
    }
    return 1;
}











