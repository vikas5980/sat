
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int minJumps(vector<int>& arr) 
{
    // code here
    int i = 0, j = 0;
    int jump = 0, len = 0;
    int arrSize = arr.size();
    
    if (arr[0] == 0)
        return -1;
    
    while(i < arrSize)
    {
        if (len >= arrSize)
        {
            jump++;
            break;
        }

        len = len + arr[i];
        jump++;
        
        i = len;
    }

    return jump;
}

// Function to find the leaders in the array.
vector<int> leaders(vector<int>& arr) 
{
    // Code here
    int j = 0;
    int len = arr.size();
    vector<int> res;
    
    res.push_back(arr[len-1]);  
    
    for (int i = len - 1; i > 0; i--)
    {
        if (arr[i-1] >= res[j])
        {
            res.push_back(arr[i-1]);
            j++;
        }
    }
    
    std::reverse(res.begin(), res.end());
    
    return res;
}

vector<int> findDuplicates(vector<int>& arr) 
{
    // code here
    int i = 0;
    int len  = arr.size();
    map<int, int> mapDup;
    vector<int> res;
    
    for (auto i : arr)
    {
        mapDup[i]++;
    }
    
    for (auto &entry : mapDup)
    {
        if(entry.second > 1)
        {
            res.push_back(entry.first);
        }
    }        

    return res;        
}


void sort012(vector<int>& arr) 
{
    // code here
    int i = 0;
    multiset<int> s;
    
    for (auto e : arr)
    {
        s.insert(e);
    }
    
    for (auto ele : s)
    {
        arr[i++] = ele;
    }
}

int main()
{

    vector<int> arr1{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << "minJumps: " << minJumps(arr1) <<endl;

    vector<int> arr2{16, 17, 4, 3, 5, 2};
    vector<int> arr3 = leaders(arr2); 
    cout << "leaders: ";
    for (auto &i : arr3)
    {
        cout << i << " ";
    }

    vector<int> arr4{2, 3, 1, 2, 3};
    vector<int> arr5 = findDuplicates(arr4); 
    cout << "\n findDuplicates: ";
    for (auto &i : arr5)
    {
        cout << i << " ";
    }

    vector<int> arr6{0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    sort012(arr6); 
    cout << "\n sort012: ";
    for (auto &i : arr6)
    {
        cout << i << " ";
    }

    return 1;
}