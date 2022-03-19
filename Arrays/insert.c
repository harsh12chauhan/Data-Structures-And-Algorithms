#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int indinsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int arr[100] = {1, 3, 5, 8, 9};
    int size = 5, element = 10, capacity = 100, index = 5;
    display(arr, size);
    indinsertion(arr, size, element, capacity, index);
    size += 1;
    display(arr, size);

    return 0;
}