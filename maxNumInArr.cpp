#include <stdio.h>

int largest(int arr[], int n)
{
    int max = -1;

    if (n < 2)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

int main() 
{
    int arr[] = { 10, 324, 45, 90, 9808 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    printf("Largest : %d", largest(arr, n));
    return 0;
}