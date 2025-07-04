#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;


// Function is to check whether two strings are anagram of each other or not.
bool areAnagrams(string& s1, string& s2) {
    // Your code here
    map<char, int> wCount;
    
    if (s1.length() != s2.length())
    {
        return false;
    }
    
    for (char &c1: s1)
    {
        wCount[c1]++;
    }
    
    for (char &c2: s2)
    {
        wCount[c2]--;
    }
    
    for (auto &count: wCount)
    {
        if (count.second > 0)
        {
            return false;
        }
    }
    
    return true;
}

// Function to check if a string is a palindrome.
bool isPalindrome(string& s) {
    // code here
    bool ret = false;
    int endIdx = (s.length()-1);
    int starIdx = 0;
    
    while (starIdx < endIdx)
    {
        if (s[starIdx] != s[endIdx])
        {
            return false;
        }
        starIdx++;
        endIdx--;
    }
    
    return true;
}

string reverseWords(string &s) 
{
    // code here
    string line(s);
    vector<string> strArr;
    
    stringstream ss(line);
    string word;
    int i = 0;
    
    while(ss >> word)
    {
        strArr.push_back(word);
    }
    
    string temp = "";
    
    for (i = (strArr.size()-1); i >= 0; i--)
    {
        temp += strArr[i];
        
        if (i != 0)
            temp += " ";
    }
    
    return temp;
}

// First non-repeating char in a string
char nonRepeatingChar(string &s) 
{
    // Your code here
    unordered_map<char, int> hash;

    for (char c: s)
    {
        hash[c]++;
    }
    
    for (auto cc : s)
    {
        for (auto &h : hash)
        {
            if (cc == h.first && h.second == 1)
            {
                return cc;
            }
        }
    }
    
    return '$';
}

// Validate an IP Address
int isIpAddressValid(string& s)
{
    // code here
    char c[5];
    int n = 0, lZero = 0;
    int j = 0;
    
    for(int i = 0; i <= s.length(); i++)
    {
        if (s[i] == '.' || s[i] == '\0')
        {
            c[j] = '\0';
            
            n = atoi(c);
            lZero++;
            
            
            if (s[i-1] == '.' && s[i] == '.')
            {
                return false;
            }
            
            if (c[0] == '0' && strlen(c) > 1)
            {
                return false;
            }  
            
            if (!((0 <= n) && (n <= 255)))
            {
                return false;
            }
            
            j = 0;
        }
        else
        {
            c[j++] = s[i];
        }
    }
    
    if (lZero < 4 || 
        lZero > 4)
    {
        return false;
    }
    
    return true;
}

// Function to check if two strings are rotations of each other or not.
bool areRotations(string &s1, string &s2) 
{
    // Your code here
    int s2Len = s2.length();
    int i = 0;
    
    if (s1.length() != s2.length())
    {
        return false;
    }
    
    for (i = 0; i < s2Len; i++)
    {
        if (s1 == s2)
            return true;
            
        /*char c = s2[s2Len - 1];
        int size = 1;

        while ((s2Len - size) > 0)
        {
            s2[s2Len - size] = s2[s2Len - (size+1)];
            size++;
        }
        
        s2[s2Len - size] = c;*/
        std::rotate(s2.begin(), s2.end()-1, s2.end());  // algorithm rotate left -> right
                                                        // default is left <- right
    }
    
    
    return false;
}

// Function to check if two strings are rotations of each other or not.
bool areRotations1(string &s1, string &s2) 
{
    // Your code here
    int s2Len = s2.length();
    int s1Len = s1.length();

    if (s1Len != s2Len)
        return false;
        
    string str(s1+s1);
    
    if (str.find(s2) == -1)
    {
        return false;
    }
    
    return true;
}

// Function to check if a string can be obtained by rotating
// another string by exactly 2 places.
bool isRotated(string& s1, string& s2) 
{
    // Your code here
    string s3(s1); 

    rotate(s1.begin(), s1.begin()+2, s1.end());
    
    if (s1 == s2)
        return true;
        
    rotate(s3.rbegin(), s3.rbegin()+2, s3.rend());
    
    if (s3 == s2)
        return true;
        
    return false;
}

int firstOccurence(string &txt, string &pat) 
{
    // Your code here
    int idx = -1, i, j, k;
    bool isPattenExist = true;
    int l1 = txt.length(), l2 = pat.length();
    
    
    for (i = 0; i < l1; i++)
    {
        isPattenExist = true;
        for (j = 0, k = i; j < l2; j++, k++)
        {
            if (txt[k] != pat[j])
            {
                isPattenExist = false;
                break;
            }
        }
        
        if (isPattenExist == true)
        {
            return i;
        }
    }
    
    return -1;
}

void reverseString(string &s) 
{
    // code here
    int start = 0;
    int end = s.length()-1;

    while (start < end)
    {
        char ch = s[start];
        s[start] = s[end];
        s[end] = ch;
        start++;
        end--;
    }
}

void reversePairOfChrInString(string &s) 
{
    // code here
    int start = 0;
    int end = s.length();

    while (start < end)
    {
        char ch = s[start];
        s[start] = s[start+1];
        s[start+1] = ch;
        if (s[start] == '\0')
        {
            s[start] = ch;
            s[start+1] = '\0';
        }
        start += 2;
    }
}

// Find the length of the longest common substring among the given strings.
int longestCommonSubstr(string& s1, string& s2) 
{
    // your code here
    int l1 = s1.length();
    int l2 = s2.length();
    int i = 0, j = 0, curr = 0;
    int maxlen = 0;
    
    for(i = 0; i < l1; i++)
    {
        for(j = 0; j < l2; j++)
        {
            curr = 0;
            while((i + curr) < l1 &&
                  (j + curr) < l2 &&
                  s1[i+curr] == s2[j+curr])
            {
                curr++;
            }
            maxlen = max(maxlen,curr);
        }
    }
    
    return maxlen;
}

// Function to check if two strings are isomorphic.
bool areIsomorphic(string &s1, string &s2) 
{
    // Your code here
    unordered_map<char, char> mp;
    int l1 = s1.length();
    int l2 = s2.length();
    bool isPresent = false;
    
    if (l1 != l2)
        return false;
        
    for (int i = 0; i < l1; i++)
    {
        
        if (mp.find(s1[i]) == mp.end())
        {
            isPresent = false;
            for (auto e: mp)
            {
                if (s2[i] == e.second)
                {
                    isPresent = true;   
                    break;
                }
            }
            
            if (isPresent == false)
            {
                mp.insert(pair<char,char>(s1[i], s2[i]));
            }
        }
        
        auto it = mp.find(s1[i]);
        
        if (!(it != mp.end() &&
            s1[i] == it->first &&
            s2[i] == it->second))
        {
            return false;        
        }
    }
    
    return true;
}

// Given a string s, you need to print the size of the longest possible substring with exactly k unique
// characters. If no possible substring exists, print -1.
int longestKSubstr(string &s, int k) 
{
    // your code here
    unordered_set<char> st;
    int i = 0, j = 0, len = s.length();
    int maxc = 0, cnt = 0;
    int isSubStrFnd = false;
    
    for(i = 0; i < len; i++)
    {
        cnt = 0;
        for (j = i; j < len; j++)
        {
            st.insert(s[j]);
            
            if (st.size() > k)
            {
                st.clear();
                isSubStrFnd = true;
                break;
            }
            cnt++;
        }
        
        maxc = max(maxc, cnt);
    }
    
    
    return (isSubStrFnd == true || st.size() == k) ? maxc:-1;
}

// remove all its adjacent duplicate characters recursively, until there are no adjacent
// duplicate characters left.
string removeUtil(string &s) 
{
    // code here
    int i = 0, idx = 0, j = 0;
    int l = s.length();
    string str;
    bool isDuplicate = false;
    
    for (i = 0; i < l ; i++)
    {
        isDuplicate = false;
        
        for(j = i+1; j < l+1; j++)
        {
            if (s[i] != s[j])
            {
                i = j-1;
                break;
            }
            isDuplicate = true;
        }
        
        if(isDuplicate == false)
            str+=s[i];
    }
    
    if (l == str.length())
        return str;
        
    return removeUtil(str);
}

// Second most repeated string in a sequence of strings
string secFrequent(string arr[], int n) 
{
    // code here.
    int i = 0;
    map<string, int> wordCounts;

    for(i = 0; i < n; i++) 
    {
        wordCounts[arr[i]]++;
    }
    
    vector<pair<string, int>> sortedWordCounts;
    for (const auto& pair : wordCounts) 
    {
        sortedWordCounts.push_back(pair);
    }
    
    sort(sortedWordCounts.begin(), sortedWordCounts.end(), [](const pair<string, int>& a, const pair<string, int>& b) 
    {
        return a.second > b.second;
    });
    
    return sortedWordCounts[1].first;
    
}

// Given a string consisting of lowercase characters and an integer k,
// the task is to count all possible substrings (not necessarily distinct)
// that have exactly k distinct characters. 
int countSubstr(string& s, int k) 
{
    // code here.
    int i = 0, j = 0, l = s.length();
    int cnt = 0, c = 0;
    set<char> st;
    
    for (i = 0; i < l; i++)
    {
        c = 0;

        for (j = i; j < l; j++)
        {
            if (s[i] == s[j] && c < k)
            {
                if (st.find(s[j]) == st.end())
                {
                    c++;
                    st.insert(s[j]);
                }
            }
            else if (c < k)
            {
                if (st.find(s[j]) == st.end())
                {
                    c++;
                    st.insert(s[j]);
                }

            }
            
            if (c >= k)
            {
                if (st.find(s[j]) != st.end())
                    cnt++;
                else
                    break;
            }
        }
        
        st.clear();
    }
    
    return cnt;
}

// Given two strings denoting non-negative numbers s1 and s2. Calculate the sum of s1 and s2.
string findSum(string &s1, string &s2) 
{
    // Your code goes here
    int l1 = s1.length(), l2 = s2.length(); 
    int len = ((l1>l2)?l1:l2);
    unsigned char carry = 0;
    string temp((len+1), '0');
    string res;
    
    for(int i = (len-1); i >= 0; --i)
    {
        unsigned char val = 0, c1 = 0, c2 = 0;
        
        if (l1-- > 0)
        {
            c1 = s1[l1] - '0';        
        }
        
        if (l2-- > 0)
        {
            c2 = s2[l2] - '0';
        }
        
        val = c1 + c2 + carry;
        if (val <= 9)
        {
            temp[len] = (val + '0');
            carry = 0;
        }
        else
        {
            unsigned char rem = val%10;
            temp[len] = (rem + '0');
            carry = 1;
        }
        --len;
    }
    
    temp[len] = carry + '0';
    
    int j = 0;
    while(temp[j] == '0')
    {
        j++;
    }
    
    while(j < temp.length())
    {
        res.push_back(temp[j++]);
    }

    
    if (0 == res.length())
        return  to_string(0);
    else
        return res;
}

// You are given two strings s1 and s2. Your task is to identify the characters
// that appear in either string but not in both (i.e., characters that are unique
// to one of the strings). Return the result as a sorted string.
string uncommonChars(string& s1, string& s2) 
{
    // code here
    set<char> st;
    set<char> stS2;
    string res;
    
    for(auto e1: s1)
    {
        st.insert(e1);
    }

    for(auto e2: s2)
    {
        stS2.insert(e2);
    }        

    for (auto ste2: stS2)
    {
        if (st.find(ste2) != st.end())
        {
            st.erase(ste2);
        }
        else
        {
            st.insert(ste2);
        }
    }

    for(auto &et: st)
    {
        res.push_back(et);
    }        
    
    return res;
}

int main()
{

    cout << "check whether two strings are anagram of each other or not." << endl;

    string s1 = "delhi";
    string s2 = "ildeh";

    if (areAnagrams(s1,s2))
    {
        cout << "strings are anagram" << endl;
    }
    else
    {
        cout << "strings are not anagram" << endl;
    }

    cout << "Function to check if a string is a palindrome." << endl;
    string s = "pelilep";
    if (isPalindrome(s))
    {
        cout << "strings is palindrome" << endl;
    }
    else
    {
        cout << "strings is not a palindrome" << endl;
    }

    string s4 = " i like this program very much ";
    cout << "reverseWords: " << reverseWords(s4) << endl;

    string s5 = "geeksforgeeks";
    cout << "nonRepeatingChar: " << nonRepeatingChar(s5) << endl;

    string s6 = "124.2.0.123";
    cout << "isIpAddressValid: " << isIpAddressValid(s6) << endl;

    string s7("abcd");
    string s8Patrn("cdab");
    cout << "areRotations: " << areRotations(s7, s8Patrn) << endl;
    cout << "areRotations via string concat: " << areRotations1(s7, s8Patrn) << endl;

    string s9 ("amazon");
    string s10 ("azonam");
    cout << "isRotated: " << isRotated(s9, s10) << endl;

    string s11 ("GeeksForGeeks");
    string s12 ("For");
    cout << "firstOccurence: " << firstOccurence(s11, s12) << endl;

    string s13("vikasM");
    reverseString(s13);
    cout << "reverseString: " << s13 << endl;

    string s14("vikasM");
    reversePairOfChrInString(s14);
    cout << "reversePairOfChrInString: " << s14 << endl;

    string s15 ("ABCDGH");
    string s16 ("ACDGHR");
    cout << "longestCommonSubstr: " << longestCommonSubstr(s15, s16) << endl;  

    string s17 ("aab");
    string s18 ("xxy");
    cout << "areIsomorphic: " << areIsomorphic(s17, s18) << endl; 

    string s19 ("aabacbebebe");
    cout << "longestKSubstr: " << longestKSubstr(s19, 3) << endl; 

    string s20 ("geeksforgeek");
    cout << "removeUtil: " << removeUtil(s20) << endl;  
    
    string arr[] = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    cout << "secFrequent: " << secFrequent(arr, 6) << endl;

    string s21 ("elfyybwnycfcmhayuczuruuwtzfnarsqgu");
    cout << "countSubstr: " << countSubstr(s21, 3) << endl;  

    string s22 ("123");
    string s23 ("3212");
    cout << "findSum: " << findSum(s22, s23) << endl;  

    string s24 ("geeksforgeeks");
    string s25 ("geeksquiz");
    cout << "findSum: " << uncommonChars(s24, s25) << endl;  
    return 1;
}