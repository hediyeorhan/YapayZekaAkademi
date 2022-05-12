#include <stdio.h>
#include <stdlib.h>
void arms(int x)
{
    int kalan;
    int toplam=0;
    int sayi=x;
    while( x>0)
    {
        kalan=x%10;
        toplam+=kalan*kalan*kalan;
        x-=kalan;
        x/=10;
    }

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
