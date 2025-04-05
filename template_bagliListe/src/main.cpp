#include <iostream>
#include <string>
using namespace std;
#include "BagliListe.hpp" 

int main()
{
    // BagliListe<int>* liste = new BagliListe<int>();

    // liste->ekle(11);
    // liste->ekle(22);
    // liste->ekle(33);
    // liste->ekle(44);
    // liste->ekle(55);

    // liste->yazdir();

    // liste->yazdir();

    BagliListe<int>* liste = new BagliListe<int>();

    // liste->ekle("11*2");
    // liste->ekle("22");
    // liste->ekle("657");
    // liste->ekle("44");
    // liste->ekle("55");
     
    // liste->yazdir();

    // liste->yazdir();
    
    liste->ekle(15);
    try
    {
        liste->ilkGetir(); // eğer throw yaptık ya bi exception yakalrsa catch blogumuza yollicak bu excepitonu
        liste->getir(5);
    }
    catch(std::out_of_range &e) // fırlatılan exception da bi nesne aslinda
    {
        cout << e.what()<<endl;
    }
    
    

}