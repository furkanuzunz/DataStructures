#include <iostream>
#include <stdio.h>

using namespace std;
void SelectionSort(int *B,int n)
{
    int temp;
    int *A = B;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int min_i = i ; // sifirinci indeksten basladik.
        for(int j = i + 1 ; j < n ; j++) // burada - 1 dememize gerek yok zaten i + 1 den baslicak ya.
        {
            if(A[j]  < A [min_i])
            {
                min_i = j;
            }
        }
        temp = A[i];
        A[i] = A[min_i]; // min elemani i ninci indekse aldik. 
        A[min_i] = temp; // simdi ise o min elemanin bulundugu indekse i ninci indeksteki elemani koyduk.
    }
} 
 
int main() 
{
int Arr[5] = {5,1,9,3,10};
int n = 5;
SelectionSort(Arr,n);
for(int i = 0; i < 5;i++)
{
    printf("%d  ",Arr[i]);
}


}