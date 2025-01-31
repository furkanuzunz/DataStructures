#ifndef OGRENCI_HPP
#define OGRENCI_HPP

#include <iostream>
using namespace std;

class Ogrenci
{
private:
    int yas;
    double boy;
    double kilo;
public:
    Ogrenci(int yas,double boy)
    {
        this->yas = yas;
        this->boy = boy;
    }
    Ogrenci()
    {
        this->yas = 0;
        this->boy= 30;
    }
    void YasIlerle(int yass)
    {
        yas += yass;
    }
    void BoyUza(double boyy)
    {
        boy += boyy;
    }
    int getYas()
    {
        return yas;
    }
    double getBoy()
    {
        return boy;
    }
    ~Ogrenci()
    {
        cout << "Ogrenci nesnesi silindi" << endl;
    }
    Ogrenci(int yaas,double booyy,double kiiloo)
    {
        this->yas = yaas;
        this->boy = booyy;
        this->kilo = kiiloo;
    }
    double getKilo()
    {
        return kilo;
    }
    template <typename YIYECEK>
    void YemekYe(YIYECEK yemek)
    {
        kilo += yemek.getKalori() / 1000;
    }
};

#endif // OGRENCI_HPP