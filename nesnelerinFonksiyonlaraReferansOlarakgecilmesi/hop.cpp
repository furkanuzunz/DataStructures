#include <iostream>
using namespace std;


// nesneleri parametre olarak verdigimde daima const ve rreferans oolarak vermemiz gerekiyr


 //bagli lsitedeki bu const mevzusu için video 22 dk 18den izle.
 //

class dortgen
{
public:
    dortgen(int i):gen(i)
    {
        //gen = i;
        cout << this << ":Dortgen()"<<endl;
    }
    ~dortgen()
    {
        cout << this << ":yokedici()"<<endl;

    }
    dortgen(const dortgen& sag)
    {
        cout << this << ":kopya()"<<endl;
    }
    int gen;
};

void fonksiyon( const dortgen &d)
{
    cout << &d << ":fonksiyon()" <<endl;
}

int main()
{
    dortgen d1(8);

    dortgen d2(d1);

    fonksiyon(d1);
}