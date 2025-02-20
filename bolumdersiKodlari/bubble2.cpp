#include <iostream>
#include <stdio.h>
// https://www.youtube.com/watch?v=8mJ-OhcfpYg
int main()
{
    int A[6] = {2,1,7,5,3,9};
    int anahtar;
    int len = 6;
    int bosluk;
    for(int i = 1;i < len - 1  ;i++ )
    {
        anahtar = A[i];
        bosluk = i;
        while(bosluk > 0 && A[bosluk - 1] > anahtar )
        {
            A[bosluk] = A[bosluk - 1];
            bosluk = bosluk - 1;// temp olarak aldıgımızla geridekileirde karşılaştırmak icin bu.
        }
        A[bosluk] = anahtar;
    }




} 