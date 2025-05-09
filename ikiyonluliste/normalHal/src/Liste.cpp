#include "Liste.hpp"
#include <iomanip>

Liste::Liste()
{
    ilk = 0;
}
Liste::~Liste()
{
    Dugum *gecici = ilk;
    while (gecici != 0)
    {
        Dugum *silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}
void Liste::ekle(int veri)
{
    Dugum *yeniDugum = new Dugum(veri);

    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        Dugum *gecici = ilk;
        while (gecici->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
        yeniDugum->onceki = gecici;
    }
    dugumSayisi++;
}

void Liste::cikar()
{
    if (ilk == 0)
        return;

    if (ilk->sonraki == 0)
    {
        delete ilk;
        ilk = 0;
    }

    else
    {
        Dugum *gecici = ilk;

        while (gecici->sonraki->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        delete gecici->sonraki;

        gecici->sonraki = 0;
    }
    dugumSayisi--;
}

Dugum* Liste::dugumGetir(int sira)
{
    int sayac = 0;

    Dugum *gecici = ilk;

    while (gecici != 0)
    {

        if (sira == sayac)
            return gecici;

        gecici = gecici->sonraki;
        sayac++;
    }
    return 0;
}

void Liste::cikar(int sira)
{
    Dugum *silinecek = dugumGetir(sira);

    if (silinecek == 0)
        return;

    Dugum *onceki_ = silinecek->onceki;
    Dugum *sonraki_ = silinecek->sonraki;

    delete silinecek;

    if (sonraki_)
        sonraki_->onceki = onceki_;
    if (onceki_)
        onceki_->sonraki = sonraki_;
    else
        ilk = sonraki_;
    
    dugumSayisi--;
}

void Liste::onuneEkle(int sira, int veri)
{
    if (ilk == 0 && sira == 0)
    {
        ilk = new Dugum(veri);
    }
    else
    {
        Dugum *dug = dugumGetir(sira);
        if (dug == 0)
            return;

        Dugum *yeni = new Dugum(veri);
        Dugum *onceki_ = dug->onceki;

        dug->onceki = yeni;
        yeni->sonraki = dug;
        yeni->onceki = onceki_;

        if (onceki_)
            onceki_->sonraki = yeni;
        else
            ilk = yeni;
    }
}
int Liste::ilkGetir()
{
    if (ilk != 0)
        return ilk->veri;
        throw std::out_of_range("Liste::ilkGetir(): Liste bos Hatasi");
}

ostream &operator<<(ostream &os, Liste &liste)
{
    using namespace std;

    os << setw(15) << "dugum adresi" << setw(15) << "veri" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;
    Dugum *gecici = liste.ilk;

    while (gecici != 0)
    {
        os<<setw(15)<<gecici<<setw(15)<<gecici->veri<<setw(15)<<gecici->onceki<<setw(15)<<gecici->sonraki<<endl;
        gecici = gecici->sonraki;
    }
    os<<"-----------------------------------------------------";
    return os;
}