#include <stdio.h>

void printing(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int *arr, int n)
{
    int key, j;
    for (int i = 0; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int a[] = {23, 34, 2, 39, 78, 3};
    int n = 6;
    printing(a, n);
    insertionsort(a, n);
    printing(a, n);
    return 0;
}