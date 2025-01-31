#include <iostream>
using namespace std;
#include <sstream>

int a2b2(int a,int b)
{
    return a*a + b*b;
}
int main(int argc,char **argv)
{
    int x,y;
    x = atoi(argv[1]);
    y = atoi(argv[2]);

    cout << "x2 + y2 = " << a2b2(x,y) << endl;
    return 0;
}
