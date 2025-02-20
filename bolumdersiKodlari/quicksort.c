#include <stdio.h>

int swap(int* a, int* b);

int Partition(int arr[],int start,int end)
{
    int pivot = arr[end];
    int pi_index = start;
    int j;
    for(j = start;j < end;j++)
    {
        if(arr[j] <= pivot)
        {
            swap(&arr[j],&arr[pi_index]);
            pi_index++;
        }
    }

swap(&arr[pi_index],&arr[end]);
return (pi_index);
}

int swap(int* a, int* b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}


void quickSort(int arr[], int start, int end)
{

    if (start < end)
    {
        int pi_index = Partition(arr,start,end);
        quickSort(arr,start,pi_index - 1);
        quickSort(arr,pi_index + 1,end);
    }
}

int main()
{
    int A[] = {7,6,5,4,3,2,1,0};
    quickSort(A,0,7);
    int i;
    for(i = 0; i < 8;i++)
        printf("%d ",A[i]);
}

// https://www.youtube.com/watch?v=COk73cpQbFQ&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=8