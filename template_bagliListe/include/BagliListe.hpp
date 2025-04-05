#ifndef BagliListe_hpp
#define BagliListe_hpp
using namespace std;
#include "Dugum.hpp"
#include <iomanip>
#include <exception>

template <typename Tur>
class BagliListe
{
public:
    BagliListe()
    {
        ilk = nullptr;
    }
    ~BagliListe()
    {
        Dugum<Tur> *gecici = ilk;
        while (gecici != 0)
        {
            Dugum<Tur> *silinecek = gecici;
            gecici = gecici->sonraki;
            delete silinecek;
            cout << "siradaki dugum:" << gecici << endl;
        }
    }
    Dugum<Tur>* sonElemaniGetir()
    {
        Dugum<Tur>* gecici = ilk;
        
        while(gecici->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        return gecici;
    }
    Dugum<Tur>* sondanBirOncekiniGetir()
    {
        Dugum<Tur> *gecici = ilk;

            while (gecici->sonraki->sonraki != 0)
            {
                gecici = gecici->sonraki;
            }
            return gecici;
    }

    Tur& ilkGetir()
    {    
        if(ilk)
        {
            return ilk->veri;
        }
        throw std::out_of_range("bagli liste ilk getir(): dugum yok hatasi"); // exceptionu fırlattık,bunu fonksiyonu cagıran yakalicak
        //mainde yakalicaz

    }

    // istedigmiz indeksi getirelim.öcne bunuun için yardımcı fonksiyonn ooluşturualim
    Dugum<Tur>* dugumGetir(int sira)  //bana istedigim dugumdeki dugumun adresini getiricek
    {
        if(sira < 0)
            return 0;
        Dugum<Tur>* gecici = ilk;
        int sayac = 0;
        while(gecici!= 0)
        {   
            if(sayac == sira)
                return gecici;
            gecici = gecici->sonraki;
            sayac++;
        }
        return gecici;
    }
    Tur& getir(int sira)
    {
        Dugum<Tur>* gecici = dugumGetir(sira);
        
        if(gecici != 0)
            return gecici->veri;
        throw std::out_of_range("bagliliste::getir(): sira hatali");
    }
    
    void ekle(const Tur &veri) // bu const mevzusu için video 22 dk 18den izle.
    {
        Dugum<Tur> *yeni = new Dugum<Tur>(veri);
        if (ilk == 0)
        {
            ilk = yeni;

            return;
        }
        // Dugum<Tur> *gecici = ilk;
        // while (gecici->sonraki != 0)
        // {
        //     gecici = gecici->sonraki;
        // } yardımcı fonksiyon haline getirdik

        Dugum<Tur>* gecici = sonElemaniGetir();
    
        gecici->sonraki = yeni;
    }
    void cikar()
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
            // Dugum<Tur> *gecici = ilk;

            // while (gecici->sonraki->sonraki != 0)
            // {
            //     gecici = gecici->sonraki;
            // } burayı fonksiyon haline getirdik

            Dugum<Tur> *gecici = sondanBirOncekiniGetir();

            delete gecici->sonraki;// son dugumu sildik
            gecici->sonraki = 0; // gecicicnin gsterdiği bağı sildik
        }
    }
    void yazdir()
    {
        cout << setw(10) << "adres" << setw(10) << "veri" << setw(15) << "sonraki" << endl;
        cout << "-----------------------------------------------------------" << endl;

        Dugum<Tur> *gecici = ilk;
        while (gecici != 0)
        {
            cout << setw(10) << gecici << setw(10) << gecici->veri << setw(15) << gecici->sonraki << endl;

            gecici = gecici->sonraki;
        }
    }

private:
    Dugum<Tur> *ilk;
};

#endif