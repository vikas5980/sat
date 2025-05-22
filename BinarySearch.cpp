#include <stdio.h>

bool binarySearch(int arr[], int start, int end, int target)
{
    if (!(start <= end))
    {
        return false;
    }
    int mid = start + ((end - start)/2);

    if (arr[mid] == target)
    {
        return true;
    }
    else if(target < arr[mid])
    {
        return binarySearch(arr, start, mid-1, target);
    }
    else
    {
        return binarySearch(arr, mid+1, end, target);
    }
}


int main() 
{
    // Array should be sorted
    int arr[] = { 10, 20, 55, 70, 78 };

    int n = sizeof(arr) / sizeof(arr[0]);
  
    if (binarySearch(arr, 0, n, 54))
    {
        printf("Found\n");

    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}