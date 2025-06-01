#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

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
    string s8("cdab");
    cout << "areRotations: " << areRotations(s7, s8) << endl;

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
    return 1;
}