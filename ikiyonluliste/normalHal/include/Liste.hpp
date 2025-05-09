#ifndef Liste_hpp
#define Liste_hpp
#include <exception>
#include <iostream>

#include "Dugum.hpp"

class Liste
{
    public: 
        Liste();
        ~Liste();
        void ekle(int veri);
        void cikar();
        void cikar(int sira);
        void onuneEkle(int sira,int veri);
        int ilkGetir();
        Dugum* dugumGetir(int sira);
        friend ostream& operator <<(ostream& os,Liste& liste);
    private:
        Dugum *ilk;
        int dugumSayisi;
};



#endif