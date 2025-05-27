#include <iostream>
#include <vector>

using namespace std;

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


// If multiple occurrences are there, please return the smallest index.
int binarysearchWhenArrWithDupEles(vector<int> &arr, int k) 
{
    // code here
    int start = 0;
    int end = arr.size()-1;
    
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        
        if (arr[mid] == k)
        {
            for (int i = mid ; i >= 0; i--)
            {
                if (arr[i-1] != arr[i])
                {
                    mid = i;
                    break;
                }
            }
            
            return mid;
        }
        else if (k < arr[mid])
        {
            end  = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    
    return -1;        
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

    vector<int> vec{1, 1, 1, 1,2,2,2,2,2,3};

    cout << "binary search index: " << binarysearchWhenArrWithDupEles(vec, 2) << endl;

    return 0;
}