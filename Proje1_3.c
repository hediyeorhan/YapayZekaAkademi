#include <stdio.h>
#include <string.h>

void main()
{
    char alfabebuyuk[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'Y', 'Z'};
    char alfabekucuk[] = {'a', 'b', 'C', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u', 'v', 'y', 'z'};
    
    char girilenmetin[30];
    char sifrelenmismetin[30];
    int k = 0; // sifrelenmismetin dizisinin indis numarasını tutmak icin.
    printf("Lutfen bir metin giriniz  : ");
    gets(girilenmetin);

    // Burada for dongusunde girilen metindeki harfleri tek tek alarak kucuk ve buyuk alfabe harfleri ile karsilastirdik.
    // Aynı harf ise char dizilerimizdeki indislere +3 ekleyerek sifreleme yaptık.
    // Son 3 indise +3 eklendiğinde dizi boyutu disina cikacagi icin bu durumları if blokları ile ayrı bir sekilde kontrol ettik.
    // Elde edilen sifre sonuclarını char dizisine atarak bir degiskende tuttuk.

    // girilen metin bosluga esit olana kadar for dongusu ile tek tek uzerinde gezindik.
    for(int i=0; girilenmetin[i]!='\0'; i++)
    {   //strlen fonksiyonu ile dizinin uzunlugunu elde ettik.
        for(int j=0; j<strlen(alfabebuyuk); j++)
        {
            if(girilenmetin[i] == alfabebuyuk[j])
            {
                if(j == 20)
                {
                    sifrelenmismetin[k] = alfabebuyuk[0];
                }
                else if(j == 21)
                {
                    sifrelenmismetin[k] = alfabebuyuk[1];
                }
                else if(j == 22)
                {
                    sifrelenmismetin[k] = alfabebuyuk[2];
                }
                else 
                {
                    sifrelenmismetin[k] = alfabebuyuk[j+3];
                }
                k++;
            }
        }
        for(int j=0; j<strlen(alfabekucuk); j++)
        {
            if(girilenmetin[i] == alfabekucuk[j])
            {
                if(j == 20)
                {
                    sifrelenmismetin[k] = alfabekucuk[0];
                }
                else if(j == 21)
                {
                    sifrelenmismetin[k] = alfabekucuk[1];
                }
                else if(j == 22)
                {
                    sifrelenmismetin[k] = alfabekucuk[2];
                }
                else 
                {
                    sifrelenmismetin[k] = alfabekucuk[j+3];
                }
                k++;
            }
        }
        if(girilenmetin[i] == ' ')
        { 
            sifrelenmismetin[k] = ' ';
            k++;
        }
        
        printf("\n  --> i : %d \n", i);

    }

    printf("\n ---------------------------------------------- \n");
    printf("\n Girilen metin : %s\n", girilenmetin);
    printf("\n Sifrelenmis metin : %s\n", sifrelenmismetin);
    printf("\n ----------------------------------------------- \n");
}
