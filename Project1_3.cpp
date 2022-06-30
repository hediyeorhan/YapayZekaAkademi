#include <iostream>
#include <string>
#include <vector>
using namespace std;


void Sifreleme(string metin)
{
    cout << "\t ---> METIN : " << metin;
    
    // Harflerin ascii karsiliklarini arastirdim ve turkce karakterler ile birlikte alfabetik siraya gore biz vectorde tuttum.
    vector<int> buyukHarfler = {97,98,99,135,100,101,102,103,167,104,141,105,106,107,108,109,110,111,148,112,114,115,159,116,117,129,118,121,122};
    vector<int> kucukHarfler = {65,66,67,128,68,69,70,71,166,72,73,152,74,75,76,77,78,79,153,80,82,83,158,84,85,154,86,89,90};
    
    // metin uzunlugu kadar dongu donmesi icin bir for dongusu
    for(int i=0; i<metin.length(); i++)
    { 
        // alfabemizde 29 harf oldugu ici 29'a kadar olan bir dongu
        for(int j=0; j<29; j++)
        {   
          
            // Olusturdugumuz vector icindeki int degerin karsiligi olan char karakter ile metindeki karakterler eslestiginde 3 indis ilerisini alarak sifreleme yapıyoruz.
            if (metin[i] == char(buyukHarfler[j])) 
            { 
                j += 3;
                j %= 29;  // Vector sonuna geldiginde indis hatası olmaması icin j ye 29 'a bolumunden kalanı atadım.
                metin[i] = char(buyukHarfler[j]);
            }
            
            else if (metin[i] == char(kucukHarfler[j])) 
            {
                j += 3;
                j %= 29;
                metin[i] = char(kucukHarfler[j]);
            }
        }
    }
    
    cout << "\n\t ---> SIFRELENMIS METIN : " << metin;
}

int main()
{
    int secim;
    string metin;
    
    // Bir menu olusturdum islemleri tekrarlamak icin.
    cout << "\n------------------------------------\n\n\t1) Yeni metin sifreleme\n\t2)Cikis\n\n------------------------------------\n\n";
    while(true)
    {
        cout << "\nLutfen bir secim yapiniz : ";
        cin >> secim;
        
        if(secim == 1)
        {
            cout << "\n Lutfen sifrelenecek metin giriniz : ";
            getline(cin >> ws, metin);
            Sifreleme(metin);
        }
        else if(secim == 2)
        {
            cout << "\n\tCikis yapiliyor ..";
            return 0;
        }
        else
        {
            cout << "\n\t ! HATALI SECIM. Lutfen 1 ya da 2 giriniz !";
        }
    }

}
