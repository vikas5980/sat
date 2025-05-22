#include <stdio.h>

int largest(int arr[], int n)
{
    int firstL = -1, secondL = -1;

    if (n < 2)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (firstL < arr[i])
        {
            secondL = firstL;
            firstL = arr[i];
        }
        else if (secondL < arr[i] && arr[i] < firstL)
        {
            secondL = arr[i];
        }
    }

    return secondL;
}

int main() 
{
    int arr[] = { 10, 324, 45, 90, 9808 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    printf("2nd Largest : %d", largest(arr, n));
    return 0;
}