#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> matrixRotate(vector<vector<int>> arr, int r, int c)
{
    vector<vector<int>> temp(c, vector<int>(r));;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            temp[j][r-1-i] = arr[i][j];   //
        }
    }

    return temp;
}

int main() 
{
    vector<vector<int>> arr = { 
                                {10, 32, 45},
                                {90, 98, 20},
                                {55, 66, 77}, 
                                {11, 22, 33}
                               };

    int r = arr.size();
    int c = arr[0].size();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf ("%d  ", arr[i][j]);
        }
        printf ("\n");
    }
  
    vector<vector<int>> arrRes = matrixRotate(arr, r, c);

    int r1 = arrRes.size();
    int c1 = arrRes[0].size();
    printf("\nRotated Matrix \n\n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf ("%d  ", arrRes[i][j]);
        }
        printf ("\n");
    }

    return 0;
}