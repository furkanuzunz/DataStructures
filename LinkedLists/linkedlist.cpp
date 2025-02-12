#include <iostream>

using namespace std;

class Dugum
{
public:
    Dugum(int veri1)
    {
        this->veri = veri1;
        sonraki = NULL;
    }
    int veri;
    Dugum *sonraki;
}

int main()
{
    Dugum *d1 = new Dugum(15);
    Dugum *d2 = new Dugum(20);
    Dugum *d3 = new Dugum(33);

    d1->sonraki = d2;
    d2->sonraki = d3;

    /*-*-*--*-*-**--**-**-**-***-*-**-*--*-**-*-*/
    Dugum *d1 = new Dugum(15);
    Dugum *d2 = new Dugum(33);
    Dugum *d3 = new Dugum(44);
    Dugum *d4 = new Dugum(55);

    d1->sonraki = d2;
    d2->sonraki = d3;
    d3->sonraki = d4;

    /*********************** */
    cout << d1->sonraki << endl;
    cout << d1->sonraki->sonraki << endl;
    cout << d1->sonraki->sonraki->sonraki << endl;

    /*********************** */

    d1 = d1 -> sonraki;
    
    d1 = d1 -> sonraki;

    d1 = d1 -> sonraki; // nulla geldik.

    /**************dongu ile gezme************ */

    Dugum *temp;
    temp = d1;

    while(temp -> sonraki != 0)
    {
        temp = temp -> sonraki;
    }
    /******eleman ekleme****** */

    Dugum *yeni;
    yeni = new Dugum(99);

    Dugum *temp = d1;

    while(temp -> sonraki != 0)
    {
        temp = temp -> sonraki;
    }
    temp -> sonraki = yeni;

}