// hpp bir baslik dosyasi aslinda. siniflari olstururuz ama implementationlarını yapmayiz.

#ifndef KISI_HPP
#define KISI_HPP

#include <iostream>
using namespace std;

class Kisi
{
    private:
        string isim;
        int boy;
    public:
          
        Kisi(string,int);
        void yaz();

};

#endif // KISI_HPP