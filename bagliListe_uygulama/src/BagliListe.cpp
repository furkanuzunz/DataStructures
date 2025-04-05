#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

BagliListe::BagliListe()
{
    ilk = 0;
}

BagliListe::~BagliListe()
{
    Dugum *gecici = ilk;
    while (gecici != 0)
    {
        Dugum *silinecek = gecici;
        gecici = gecici->sonraki;
         delete silinecek;
        cout << "siradaki dugum:" << gecici << endl;
    }
}
void BagliListe::ekle(int veri)
{
    Dugum *yeni = new Dugum(veri);
    if (ilk == 0)
    {
        ilk = yeni;

        return;
    }
    Dugum *gecici = ilk;
    while (gecici->sonraki != 0)
    {
        gecici = gecici->sonraki;
    }
    gecici->sonraki = yeni;
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

        while(gecici->sonraki->sonraki!=0)
        {
            gecici=gecici->sonraki;
        }

        delete gecici->sonraki;
        gecici->sonraki = 0;
    }


}

void BagliListe::yazdir()
{
    cout << setw(10) << "adres" << setw(10) << "veri" << setw(15) << "sonraki" << endl;
    cout << "-----------------------------------------------------------" << endl;

    Dugum *gecici = ilk;
    while (gecici != 0)
    {
        cout << setw(10) << gecici << setw(10) << gecici->veri << setw(15) << gecici->sonraki << endl;

        gecici = gecici->sonraki;
    }
}