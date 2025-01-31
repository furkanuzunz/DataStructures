#include <iostream>
using namespace std;

#include <cstdlib>

int *diziOlusturVeDegerAta(int elemanSayisi)
{
    srand(time(0));

    int *dizi = new int[elemanSayisi];
    for (int i = 0; i < elemanSayisi; i++)
    {
        dizi[i] = rand() & 100;
    }
    return dizi;
}

void diziYazdir(int *olusanDizi, int boyut)
{
    for (int i = 0; i < 10; i++)
    {

        cout << "p+" << i << "  : " << *(olusanDizi + i) << endl;
    }
}

int main()
{
    int *olusanDizi = diziOlusturVeDegerAta(10); // olsuturulan dizinin baslangic adresi döndü biz d eonu pointer ile tuttuk.
    diziYazdir(olusanDizi, 10);

    return 0;
}