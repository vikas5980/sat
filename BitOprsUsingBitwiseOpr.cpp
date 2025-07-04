#include <iostream>

using namespace std;

// You are given two numbers a and b. The task is to count the number
// of bits needed to be flipped to convert a to b.
int countBitsFlip(int a, int b) 
{
    // code here
    int a1 = 0, b1 = 0;
    int cnt = 0;
    
    while (a != 0 || b != 0 )
    {
        a1 = 0; b1 = 0;
        
        a1 = a & 1;
        b1 = b & 1;
        
        if (a1 ^ b1)
        {
            cnt++;        
        }
        else if (a == 0 && (b & 1))
        {
            cnt++;
        }
        else if (b == 0 && (a & 1))
        {
            cnt++;
        }            
        
        a = a >> 1;
        b = b >> 1;
    }
    
    return cnt;
}


int main() 
{
    // Array should be sorted
    cout << "countBitsFlip: " << countBitsFlip(20, 25) << endl;

    return 0;
}