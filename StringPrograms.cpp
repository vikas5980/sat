#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <unordered_map>

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


    return 1;
}