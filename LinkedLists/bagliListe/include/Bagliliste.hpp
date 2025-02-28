#ifndef BagliListe_hpp
#define BagliListe_hpp

#include "Dugum.hpp"
using namespace std;
class BagliListe
{
    public:
        BagliListe();
        ~BagliListe();

        void ekle(int veri);

        void yazdir();
        void cikar();
    private:
        Dugum* ilk;

};

#endif