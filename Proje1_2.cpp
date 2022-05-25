#include <iostream>
using namespace std;

// ikilik tabanda toplama islemini gerceklestirmek icin bir fonksiyon tanimladik.
void ikiliktabantoplama(long sayi1, long sayi2)
{   
    // toplam dizisine index degerlerine gore atama yapmak icin indis degiskeni tutuyoruz.
    // 1 ve 1 toplandigi durumlarda sonuc 10 oldugu icin 1 sayisini diger toplama aktarmak icin eldesayi degiskeni tutuyoruz.
    
    int indis = 0, eldesayi = 0, toplam[30];

    // ikisinden biri 1 oldugu durumlarda ya da ikiside 1 oldugu durumlarda uygulanacak islemler
    while (sayi1 != 0 || sayi2 != 0)
    {
        toplam[indis++] =(sayi1 % 10 + sayi2 % 10 + eldesayi) % 2;   // iki sayinin da 10'a bolumunden kalan aliniyor elde deger varsa ekleniyor ve 2 ye bolumundan kalan aliniyor.
        // yandaki sayiya aktarmak icin elde hesaplaması yapiliyor.
        // 1 ve 1 toplandiginda 10 oluyor burada 10'a bolumunden kalan 0 oldugu icin bu sekilde aliniyor daha sonra 2 ye bolunuyor cikan sonuc 1 veya 0 oluyor ve eldeye aktariliyor.
        eldesayi =(sayi1 % 10 + sayi2 % 10 + eldesayi) / 2;
        
        // toplama islemi yapilan basamaklarin sayidan cikarilmasi icin 10'a bolunerek basamak eksiltiliyor.
        sayi1 = sayi1 / 10;
        sayi2 = sayi2 / 10;
    }
    // eldesayi 0 degilken yani 1 iken toplam dizisine ekleniyor.
    if (eldesayi != 0)
    {
        toplam[indis++] = eldesayi;
    }
        
    --indis;
    cout<<" --> SONUC : ";
    while (indis >= 0)
    {
        cout<<toplam[indis--];
    }
}
main()
{
 
    long sayi1, sayi2;
 
    cout<<" -- Sayi1 giriniz : ";
    cin>>sayi1;
    cout<<" -- Sayi2 giriniz : ";
    cin>>sayi2;

    ikiliktabantoplama(sayi1, sayi2);


}
