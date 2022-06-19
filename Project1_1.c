#include <stdio.h>
#include <stdlib.h>
void arms(int x)
{
    int kalan;
    int toplam=0;
    int sayi=x;
    
    // girilen sayinin basamak değerlerini tek tek aliyoruz ve üçüncü dereceden kuvvetlerini toplam değişkenine ekliyoruz.
    
    while( x>0)
    {
        kalan=x%10;
        toplam+=kalan*kalan*kalan;
        x-=kalan;
        x/=10;
    }
    
    // Kupleri alinan basamak degerleri toplami, sayinin kendisine esitse sayi armstrong sayidir diyoruz.
    
    if(toplam==sayi)
    {
        printf("Sayi armstrong..");
    }
    else
    {
        printf("Sayi armstong degil..");
    }
}

int main()
{
    int deger;
    printf("Sayi degeri giriniz:");
    scanf("%d",&deger);
    arms(deger);
    return 0;
}
