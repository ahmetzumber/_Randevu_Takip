/*
 * kutuphanem.h
 * Butun fonksiyonlarimin bulundugu header dosyasi
 * Odev_2
 * 23.12.2019 odevi yaptigim tarih
 * Ahmet Zumberoglu - ahmet.zumberoglu@stu.fsm.edu.tr
 */
#ifndef KUTUPHANEM_H
#define KUTUPHANEM_H
#include <stdio.h>

typedef struct {
    char *hastaAdi;
    int gun;
    int saat;
}Randevu;

FILE *file;
void gunleriYazdir(void);
void ismeGoreRandevuArama(char *);
void guneGoreRandevuArama(int);
void randevuOlustur(char *, int, int);
void randevulariYazdir(void);
void randevuSil(char *);
int isDecimal(char *str);
int length(char*);
char *split(char*,char);
int compareTo(char *str1, char *);
int findFirstNumber(char *);
int isDigit(char);
int * findFirstTwoNumber(char *);
int randevuGunControl(int , int);

#endif


