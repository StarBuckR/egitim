#include<stdio.h>

// fonkiler
void diziElemanEkle(int *, int);

int main() {
    int sayi;
    scanf("%d", &sayi);// sayıyı kullanıcıdan alıyoruz
    int asalCarpan[100] = {[0 ... 99] = 0 };
    int bolen = 2;
    int ilkBolen = 1; // asal çarpanı sadece 1 defa eklemek istiyoruz, kontrol amaçlı
    
    while(sayi!=1) {
        if(sayi%bolen==0) {
            sayi = sayi / bolen;
            if(ilkBolen) {
                diziElemanEkle(asalCarpan, bolen);
                ilkBolen = 0;
            }
        } else {
            bolen++;
            ilkBolen = 1;
        }        
    }

    // yazdirma işlemi
    for(int i=0;i<100;i++) {
        if(asalCarpan[i] != 0)
            printf("%d ", asalCarpan[i]);
    }
    printf("\n");
    return 0;
}

void diziElemanEkle(int * dizi, int eleman) {
    static int index = 0;
    dizi[index] = eleman;
    index++;
}