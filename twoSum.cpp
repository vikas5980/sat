#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target)
{
    unordered_map<int,int> m;
    int a, b;
    vector<int> result;

    for(int i = 0; i < nums.size(); i++)
    {
        a = nums[i];
        b = target - a;
        if (m.find(b) != m.end())
        {
            result.push_back(m[b]);
            result.push_back(i);
        }
        else
        {
            m.insert(pair<int,int>(a,i));
        }
    }
    return result;
}


int main() 
{
    vector<int> arr{1,2,4,3,5};

    vector<int> res = twoSum(arr, 5);
    for (auto i: res)
    {
        cout << " ," << i;
    }
    return 0;
}