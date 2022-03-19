#include <stdio.h>

void printing(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionsort(int *a, int n)
{
    int indexofmin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;
    }
}

int main()
{
    int arr[] = {5, 13, 27, 8, 1};
    int n = 5;
    printing(arr, n);
    selectionsort(arr, n);
    printing(arr, n);
    return 0;
}