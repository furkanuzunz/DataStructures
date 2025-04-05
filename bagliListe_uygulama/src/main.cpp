#include <iostream>

#include "BagliListe.hpp" 

int main()
{
    BagliListe* liste = new BagliListe();

    liste->ekle(11);
    liste->ekle(22);
    liste->ekle(33);
    liste->ekle(44);
    liste->ekle(55);

    liste->yazdir();

    liste->yazdir();
    
}