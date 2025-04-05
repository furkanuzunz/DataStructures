#ifndef BagliListe_hpp
#define BagliListe_hpp
#include <exception>
#include "Dugum.hpp"

#include <iomanip>
using namespace std;


template <typename Tur>
class BagliListe
{
    public:
        BagliListe()
        {
            ilk = 0;
            dugumSayisi = 0;
            
        }
        ~BagliListe()
        {
            Dugum<Tur>* gecici = ilk;

            for(int i = 0;i < dugumSayisi;i++)
            {
                Dugum<Tur> *silinecek = gecici;
                gecici = gecici->sonraki;
                delete silinecek;
            }
        }
        void ekle(const Tur& veri)
        {
            Dugum<Tur> *yeni = new Dugum<Tur>(veri);
            if(ilk == nullptr)
            {
                ilk = yeni;
                ilk->sonraki = ilk;
            }
            else
            {
                Dugum<Tur>*gecici = ilk;
                while(gecici->sonraki!= ilk)
                {
                   gecici =  gecici->sonraki;
                }
                gecici->sonraki = yeni;
                yeni->sonraki=ilk;
            }
            dugumSayisi++;
        }

        void cikar()
        {
            if(ilk == 0)
                return;
            if(ilk->sonraki==ilk)
            {
                delete ilk;
                ilk = 0;
            }
            else
            {
                Dugum<Tur>*gecici = ilk;
                while(gecici->sonraki->sonraki!= ilk)
                {
                   gecici =  gecici->sonraki;
                }
                delete gecici->sonraki;
                gecici->sonraki=ilk;
            }
            dugumSayisi--;
        }
        void yazdir()
        {
            Dugum<Tur>* gecici = ilk;
            for(int i = 0;i < dugumSayisi;i++)
            {
                cout << gecici->veri<<",";
                gecici = gecici->sonraki;
            }
        }


    private:
        Dugum<Tur>* ilk;
        int dugumSayisi;
};







#endif