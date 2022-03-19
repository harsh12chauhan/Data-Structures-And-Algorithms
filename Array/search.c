#include <stdio.h>
int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            // return i;
            return printf("The %d was found in the index %d", element, i);
        }
    }
    //  return -1;
    return printf(" element Not found");
}

int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            // return mid;
            return printf("The %d was found in the index %d", element, mid);

        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // return -1;
    return printf(" Element Not found");
}
int main()
{
    //==============================================  LINEAR SEARCH UNSORTED ARRAY
    // int arr[10]={1,13,7,12,3,6,5,8,2};
    // int size = sizeof(arr)/sizeof(int);
    // int element = 8;
    // int indexofelement = linearsearch(arr,size,element);
    // printf("The %d was found in the index %d",element,indexofelement);

    //============================================== BINARY SEARCH FOR SORTED ARRAY
    int arr[10] = {1, 3, 5, 34,222,333,444,555,666};
    int size = sizeof(arr) / sizeof(int);
    int element = 2;
    int indexofelement = binarysearch(arr, size, element);
    // printf("The %d was found in the index %d", element, indexofelement);
    return 0;
}