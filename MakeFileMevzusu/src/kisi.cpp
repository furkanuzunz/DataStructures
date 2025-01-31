#include "kisi.hpp"

Kisi::Kisi(string isim, int boyut)
{
    this->isim = isim; // The this keyword in C++ is a pointer that refers to the current object instance
    this->boy = boyut;
}

void Kisi::yaz()
{
    cout <<"isim"<<isim<<endl;
    cout << "boy"<<boy << endl;
}
