#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Ogrenci
{
public:
    Ogrenci()
    {
        this->numara = 1000 * (1 + rand() % 3) + rand() % 999;
        this->sinif = 1 + rand() % 4;
    }
    int numaraGetir() const
    {
        return numara;
    }
    int sinifGetir() const
    {
        return sinif;
    }
    friend ostream &operator<<(ostream &os, const Ogrenci &ogrenci)
    {
        os << setw(5) << ogrenci.numaraGetir() << "-" << setw(4) << right << ogrenci.sinifGetir() << endl;
        return os;
    }

private:
    int numara;
    int sinif;
};

void diziSifirla(Ogrenci **dizi, int ogrenciSayisi)
{
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        dizi[i] = nullptr;
    }
}

void ogrenciEkle(Ogrenci **dizi, int ogrenciSayisi)
{
    cout << "sira giriniz" << endl;
    int sira;
    cin >> sira;
    if ((sira < ogrenciSayisi && sira > 0) && dizi[sira] == nullptr)
        dizi[sira] = new Ogrenci();
    else
        cout << "lütfen gecerli bir sayi giriniz" << endl;
}

void diziYoket(Ogrenci **dizi, int ogrenciSayisi)
{
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        if (dizi[i] != NULL)
        {
            delete dizi[i];
        }
    }
    delete[] dizi; // iaşretçi dizimizi de sildik heapteki.
}

void ogrenciSil(Ogrenci **dizi, int ogrenciSayisi)
{
    cout << "silmek sitediginiz sirayi giriniz" << endl;
    int silim;
    cin >> silim;
    if ((silim < ogrenciSayisi && silim >= 0) && dizi[silim] != NULL)
    {
        delete dizi[silim];
        dizi[silim] = NULL;
    }
}

void diziYazdir(Ogrenci **dizi, int ogrenciSayisi)
{
    cout << setw(8) << left << "indeks" << setw(2) << " " << setw(10) << "icerik" << setw(2) << "      |" << setw(10) << "gosterilen" << endl;
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        cout << setw(5) << left << "dizi[" << i << "] " << setw(2) << " " << setw(10) << dizi[i] << setw(2) << "      |";

        if (dizi[i] != nullptr)
        {
            cout << setw(10) << *dizi[i]; // 10.video dk 23-25 arasi izle önemli.
        }
        else
        {
            cout << setw(10) << "---------" << endl;
        }
        // cout << *dizi[i]; // aşağıdan gönderdiğimiz ogrenci[i] işaretçisinin sakladığı nesne adresinin içine girip nesnenin elemanlarını/içerigini yazdiriyoruz.
    }
}

int main()
{
    int ogrenciSayisi = 10;
    Ogrenci **ogrenciListesi = new Ogrenci *[ogrenciSayisi]; // burada yazan Ogrenci aslinda gösterdiği şeyin türünü gösteriyor.şuan bi nesne olusturmadik.gosterdigi verinin türünü belirtir.

    while (true)
    {
        diziYazdir(ogrenciListesi, ogrenciSayisi);
        cout << "1 - ogrenci ekle" << endl;
        cout << "2 - ogrenci sil" << endl;
        cout << "3 - cikis" << endl;
        int secim;
        cin >> secim;
        if (secim == 1)
        {
            ogrenciEkle(ogrenciListesi, ogrenciSayisi);
        }
        else if (secim == 2)
        {
            ogrenciSil(ogrenciListesi, ogrenciSayisi);
        }
        else
        {
            diziYoket(ogrenciListesi, ogrenciSayisi);
            break;
        }
    }
}