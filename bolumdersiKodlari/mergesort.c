#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    // m medium
    // l left
    // r right
    int i, j, k;
    int count_fromleft = m - l + 1;
    int count_fromright = r - m;

    // sol ve sagi tutmak icin arraylere ihtiyacımız var.
    int *Left = (int *)malloc(count_fromleft * sizeof(int));
    int *Right = (int *)malloc(count_fromright * sizeof(int));

    for (i = 0; i < count_fromleft; i++)
        Left[i] = arr[l + i]; // sol dizimize soldakileri gönderdik.

    for (j = 0; j < count_fromright; j++)
        Right[j] = arr[m + 1 + j]; // m + 1 cunku aten aşağıdan biz m + 1 den ayarladik saği

    // simdi bu gecici sol ve sağ dizileri Arr dizimize tekrar eklicez.

    i = 0;
    j = 0;
    k = l; //  soldan baslicaz eklemeye

    while (i < count_fromleft && j < count_fromright)
    {
        if (Left[i] < Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else if (Left[i] >= Right[j])
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < count_fromleft)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < count_fromright)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);     // sol icin aslinda bura.soldan baslıyor ortancaya kadar.
        mergeSort(arr, m + 1, r); // bu da sağ için.ortancanin 1 yanından baslıyor en sağa doğru işte mantık.

        merge(arr, l, m, r);
    }
}

void printArray(int arr[],int size)
{
    int i;
    for(i = 0;i < size;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}