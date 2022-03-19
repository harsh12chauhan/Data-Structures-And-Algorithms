#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printing(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
//  ============================== maximum function for getting the max element of the array
int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

//  ============================= function for countsort
void countsort(int *A, int n)
{
    int i, j;
    // Find the maximum element is A
    int max = maximum(A, n);

    // Create the counter array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {5, 13, 27, 8, 1};
    int n = 5;
    printing(A, n);
    countsort(A, n);
    printing(A, n);
    return 0;
}