#include "BagliListe.hpp"
#include <iostream>
#include<iomanip>
BagliListe::BagliListe()
{
    ilk=0;// bagli listeden bir nesne olusturdugumuzda hicbir düğümü göstermemeli.
    //zaten ilk in sıfır olup olmamasını kontrol mekanizması olarak kullanıyoruz biz

}
BagliListe::~BagliListe()
{
    Dugum* gecici = ilk;

    while(gecici!=0)
    {
        Dugum* silinecek = gecici;
        cout << "siradaki dugum:"<<gecici<<endl;
        gecici= gecici->sonraki;
        delete silinecek;
    }


}
void BagliListe::ekle(int veri)
{
    Dugum* yeni = new Dugum(veri);
    if(ilk==0)
    {
        ilk = yeni;
        return;
    }
   
    Dugum* gecici = ilk;
    while(gecici->sonraki!=0)
        gecici= gecici->sonraki;
    gecici->sonraki = yeni;
} 
void BagliListe::yazdir()
{
    using namespace std;
    Dugum* gecici = ilk;
    cout<<"-------------------------------"<<endl; 
    cout<<setw(10)<<"Adres:"<<setw(10)<<"Veri:"<<setw(15)<<"Sonraki:"<<endl; 
    cout<<"-------------------------------"<<endl;  
    while(gecici!=0)
    {
        cout<<setw(10)<<gecici<<setw(10)<<gecici->veri<<setw(15)<<gecici->sonraki<<endl;
        cout<<"-------------------------------"<<endl;
        gecici= gecici->sonraki;  
    }
          
}

void BagliListe::cikar()
{
    if(ilk==0)  return;

    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
    }
    else
    {
        Dugum* gecici = ilk;

        while(gecici->sonraki->sonraki!=0)// aslinda 
        {
            //burada eğer döngü koşulunu gecici->sonraki yaparsam,son düğümü işaret edecek kadar goturrusem,bagı koparamam,
            //bagı koparan ondan önceki düğündür.sonraki düğümü sıfır yapacak cunku ve bagı koparcak.
            //eger gecici->sonraki dersen aslinda direkt sona gidiyor ya, eğer gecici->sonraki->sonraki != 0 dersek
            // son dugume gitmeden bakar he sonrakinin sonraki 0 ise durayım sondan önceki düğümüm ben,bagı da kopariyim der.
            gecici=gecici->sonraki;
        }
        // o zaman dongu bittiğinde gecici işaretçisi sondan bi önceki düğümü gösteryor olacak.
        //öncelikle son düğümü silicem,ardından gecicinin gosterdiği yeri son düğüm yapılcak

        delete gecici->sonraki;
        gecici->sonraki = 0;//burda da bagı koparmıs olduk.
    }
}