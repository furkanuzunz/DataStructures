#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
using namespace std;

template <typename Tur>
class Dugum
{
public:
    Dugum(const Tur &veri)
    {
        this->veri = veri;
        this->sonraki = 0;
    }
    ~Dugum()
    {

        cout << "dugumun silindi ------->";
    }
    Tur veri;
    Dugum<Tur> *sonraki;
    // şablon sınıfıı tanımlarken sınıf iki dosya içerisinde tutulamaz
    // fonksiyon gövdeleriyle ön tanımını iki ayrı dosyada tutamazsınız.
}; // derleyicinin şablon oluturabilmeis için tek dosya içeirisinde görmesi lazım

#endif
