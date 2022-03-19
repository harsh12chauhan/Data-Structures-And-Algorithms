#include <stdio.h>

void printing(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// ==============================bubble sort with adaptive
void bubbleadaptive(int *arr, int n)
{
    int temp;
    int issorted = 0; // used for checking if the  array is already sorted (adaption)
    for (int i = 0; i < n - 1; i++)
    {
        printf("This is pass %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}

void bubble(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        printf("This is pass %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 5, 7,8 , 12, 28};
    // int arr[] = {1, 2, 3, 6, 7, 8};
    int n = 6;
    printing(arr, n);
    bubble(arr, n);
    // bubbleadaptive(arr,n); //======= This is fast and better
    printing(arr, n);
    return 0;
}