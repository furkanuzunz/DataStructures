#include <iostream>
#include <stdio.h>

int main()
{
int A[6] = {2,7,4,1,5,3};
int flag;
int n = 6;
int temp;

for(int i = 0; i < n - 1; i++)
{
    flag = 0;
    for(int j = 0; j < n - 1 - i; j++ )
    {
        if(A[j] > A[j + 1])
        {
            temp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = temp;
            flag = 1;
        }
    }
    if(flag==0)
        break;
}

int k = 0;
while(k< 6)
{
    printf("%d ",A[k]);
    k++;
}



}