#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
BagliListe::BagliListe()
{
    ilk = 0;
    dugumSayisi = 0;
}

BagliListe::~BagliListe()
{
    Dugum *gecici = ilk;
    for(int i = 0;i < dugumSayisi;i++)
    {
        Dugum *silinecek = gecici;

        gecici = gecici->sonraki;

        delete silinecek;
    }
}

void BagliListe::ekle(int veri)
{
    Dugum *yeni = new Dugum(veri);

    if (ilk == 0)
    {
        ilk = yeni;
        ilk->sonraki = ilk;
        return;
    }
    // else
    // {
    //     Dugum *gecici = ilk;
    //     int turSayisi;
    //     while (turSayisi != dugumSayisi - 1)
    //     {
    //         turSayisi++;
    //         gecici = gecici->sonraki;
    //     }

    //     yeni->sonraki = ilk;
    //     gecici->sonraki = yeni;
    // }
    //else için ikinci yöntem ise
    else
    {
        Dugum *gecici = ilk;
        while(gecici->sonraki != ilk)
        {
            gecici = gecici->sonraki;
        }
        yeni->sonraki=ilk;
        gecici->sonraki=yeni;
    }
    dugumSayisi++;
}

void BagliListe::cikar()
{
    if (ilk == 0)
    {
        return;
    }
    if (ilk->sonraki != ilk)
    {
        delete ilk;
        ilk = 0;
    }
    else
    {
        Dugum *gecici = ilk;
        while (gecici->sonraki->sonraki != ilk)
        {
            gecici = gecici->sonraki;
        }
        delete gecici->sonraki;
        gecici->sonraki = ilk;
    }
    dugumSayisi--;
}

void BagliListe::yazdir()
{
    Dugum *gecici = ilk;

    cout << "---------------------------------" << endl;
    cout << setw(10) << "Adres:" << setw(10) << "Veri:" << setw(15) << "Sonraki:" << endl;
    cout << "---------------------------------" << endl;

    for(int i = 0;i < dugumSayisi;i++)
    {
        cout << setw(10) << gecici << setw(10) << gecici->veri << setw(15) << gecici->sonraki << endl;
        cout << "------------------------------" << endl;
        gecici = gecici->sonraki;
    }
}
