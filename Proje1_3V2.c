#include <stdio.h>


void Sifreleme(char metin[100])
{
    char harf;
    for (int i = 0; metin[i] != '\0'; ++i)
    {
        harf = metin[i];
        if (harf >= 'a' && harf <= 'z')
        {
            harf = harf + 3;
            if (harf > 'z')
            {
                harf = harf - 'z' + 'a' - 1;
            }
            metin[i] = harf;
        }
        else if (harf >= 'A' && harf <= 'Z')
        {
            harf = harf + 3;
            if (harf > 'Z')
            {
                harf = harf - 'Z' + 'A' - 1;
            }
            metin[i] = harf;
        }
    }
    printf("Sifrelenmis metin : %s", metin);
}
int main()
{
    char metin[100];
    printf("Metin giriniz : ");
    gets(metin);
    
    Sifreleme(metin);

    return 0;
}
