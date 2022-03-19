#include <stdio.h>

void printing(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

//  ============================= partition function for quicksort
int partition(int A[], int low, int high)
{

    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
//  ============================= quicksort function
void quicksort(int A[], int low, int high)
{
    int partitionindex; // index of pivot after partition
    if (low < high)
    {
        partitionindex = partition(A, low, high);
        quicksort(A, low, partitionindex - 1);  // sort left subarray
        quicksort(A, partitionindex + 1, high); // sort right subarray
    }
}

int main()
{
    int A[] = {5, 13, 27, 8, 1, 234, 22, 56, 33, 743};
    int n = 10;
    printing(A, n);
    quicksort(A, 0, n - 1);
    printing(A, n);
    return 0;
}