#include <stdio.h>
#include <iostream>
#include <ostream>
using namespace std;

class vector
{
    public:
        vector(int x,int y,int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
    
    friend ostream& operator<<(ostream &os,const vector &v1);


    private:
        int x,y,z;
};

ostream& operator<<(ostream &os,const vector &v1)
{ //buradaki ilk parametre olan &os aslında cagrıldıgı sınıf nesnesi oluyor cout yani

    os << "x,y,z" << v1.x,v1.y,v1.z<< endl;

    return os; // aslidna bu cout. ostream onun sınıf türü

}

int main()
{
    vector v1(2,3,4);
    cout << v1;
}