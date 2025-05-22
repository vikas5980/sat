#include <stdio.h>

int smallest(int arr[], int n)
{
    int min = arr[0];

    if (n < 2)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    return min;
}

int main() 
{
    int arr[] = { 10, 324, 45, 90, 9808 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    printf("Smallest : %d", smallest(arr, n));
    return 0;
}