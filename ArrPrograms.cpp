
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <unordered_set>

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

//Reverse array in groups
void reverseInGroups(vector<int> &arr, int k) 
{
    // code here
    stack<int> st;
    int len = arr.size();
    int cnt = 0, i = 0;
    int cnt1 = 0, cnt2 = 0; 
    
    while(len > 0)
    {
        cnt = 0;
        
        while(len > 0 && cnt < k)
        {
            st.push(arr[cnt1++]);
            cnt++;
            len--;
        }
        
        while (st.empty() == false)
        {
            auto ele = st.top();
            st.pop();
            
            arr[cnt2++] = ele;
        }
    }
}

int majorityElement(vector<int>& arr) 
{
    // code here
    int len = arr.size();
    int majEle = len/2;
    int ret = -1, i = 0;
    
    map<int, int> hash;
    
    for (auto i : arr)
    {
        hash[i]++;
    }
    
    for (auto &e : hash)
    {
        if (e.second > majEle)
        {
            ret = e.first;
            break;
        }
    }
    
    return ret;
}

// k : find kth smallest element and return using this function
int kthSmallest(vector<int> &arr, int k) 
{
    // code here
    int ret = 0;
    set<int> sortSet;
    
    for(auto i : arr)
    {
        sortSet.insert(i);
    }
    
    int count = 1;
    
    for(auto &e : sortSet)
    {
        if (count == k)
        {
            ret = e;
            break;
        }
        count++;
    }        
    
    return ret;
}

// Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10].
// The length of the longest subarray with a sum of 15 is 6.
int longestSubarray(vector<int>& arr, int k) 
{
    // code here
    int sum = 0;
    int i = 0, j = 0; 
    int arrSize = arr.size();
    int eleCnt = 1, max = 0;
    
    for (i = 0; i < arrSize; i++)
    {
        sum = 0;
        eleCnt = 0;
        
        for (j = i; j < arrSize; j++)
        {
            eleCnt++;
            sum = sum + arr[j];
            
            if (sum == k)
            {
                if (eleCnt > max)
                {
                    max = eleCnt;
                }
            }
        }
    }
    
    return max;
}

// findTwoElement: Missing And Repeating elements within the range [1,n]
vector<int> findTwoElement(vector<int>& arr) 
{
    // code here
    vector<int> res;
    int len = arr.size();
    map<int, int> m;
    
    for (auto &i: arr)
    {
        m[i]++;
        
        if (m[i] > 1)
        {
            res.push_back(i);
        }
    }
    
    int c = 1;
    for (auto &j: m)
    {
        if (!(j.first == c))
        {
            res.push_back(c);
            break;
        }
        c++;
    }
    
    if(c == len)
    {
        res.push_back(len);
    }
    
    return res;
}

// Function to find equilibrium point in the array.
int findEquilibrium(vector<int> &arr) 
{
    // code here
    int len = arr.size();
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0; 
    
    for(i = 0; i < len; i++)
    {
        sum1 = 0;
        sum2 = 0; 
        
        for(j = 0; j < len; j++)
        {
            if (j < i)
            {
                sum1 = sum1 + arr[j];
            }
            else if (j > i)
            {
                sum2 = sum2 + arr[j];
            }
        }
        
        if (sum1 == sum2)
        {
            return i;
        }
    }
    
    return -1;
}

// peak element because arr[i-1] < arr[i] > arr[i+1]
// Consider the element before the first element and the element after the last element to be negative infinity
int peakElement(vector<int> &arr) 
{
    // Your code here
    int len = arr.size();
    int i = 0, j = 0;
    int ret = 0;
    int prev = INT_MIN;
    int last = INT_MAX;
    
    for (i = 0; i < len; i++)
    {
        if (i == 0)
            prev = INT_MIN;
        else
            prev = arr[i-1];
            
        if (i == len-1)
            last = INT_MIN;
        else
            last = arr[i+1];
        
        
        if (prev < arr[i] && arr[i] > last)
        {
            ret = i;
            return ret;
        }
    }
    
    return ret;
}

// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(vector<int>& arr, int d) 
{
    // code here
    int len = arr.size();
    int rotate = d%len;
    int i = 0;
    
    if (rotate == 0)
        return;
        
    while(rotate--)
    {
        int temp = arr[0];
        for(i  = 0; i < len-1; i++)
        {
            arr[i] = arr[i+1];
        }
        arr[i] = temp;
    }
}

// Function to check if b is a subset of a
bool isSubset(vector<int> &a, vector<int> &b) 
{
    // Your code here
    unordered_multiset<int> ms;
    
    for(auto e: a)
    {
        ms.insert(e);
    }
    
    for (auto e1 = b.begin(); e1 != b.end(); e1++)
    {
        auto it = ms.find(*e1);
        if(it == ms.end())
        {
            return false;
        }
        
        ms.erase(it);
    }

    return true;
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

    vector<int> arr7{1, 2, 3, 4, 5};
    cout << "\n reverseInGroups: ";
    reverseInGroups(arr7, 3);
    for (auto &i : arr7)
    {
        cout << i << " ";
    }

    vector<int> arr8{1, 1, 2, 1, 3, 5, 1};
    cout << "\n majorityElement: " << majorityElement(arr8);

    vector<int> arr9{7, 10, 4, 3, 20, 15};
    cout << "\n kthSmallest: " << kthSmallest(arr9, 3);

    vector<int> arr10{10, 5, 2, 7, 1, -10};
    cout << "\n longestSubarray: " << longestSubarray(arr10, 15);

    vector<int> arr11{4, 3, 6, 2, 1, 1};    // 5-missing, 1-repeating elements
    cout << "\n reverseInGroups: ";
    vector<int> arr12 = findTwoElement(arr11);
    for (auto &i : arr12)
    {
        cout << i << " ";
    }

    vector<int> arr13{-7, 1, 5, 2, -4, 3, 0};
    cout << "\n findEquilibrium: " << findEquilibrium(arr13);

    vector<int> arr14{1, 2, 4, 5, 7, 8, 3};
    cout << "\n peakElement: " << peakElement(arr14);

    vector<int> arr15{1, 2, 3, 4, 5};
    cout << "\n rotateArr: ";
    rotateArr(arr15, 2);
    for (auto &i : arr15)
    {
        cout << i << " ";
    }

    vector<int> arr16{11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> arr17{11, 3, 7, 1, 7};
    cout << "\n isSubset: " << isSubset(arr16, arr17);

    return 1;
}