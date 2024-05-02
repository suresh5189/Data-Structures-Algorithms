// Given a string s, partition s such that every substring of the partition is a palindrome
// Return all possible palindrome partitioning of s.

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

// Constraints:
// 1 <= s.length <= 16
// s contains only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void func(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            func(i + 1, s, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> PalindromePartition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    return res;
}

int main()
{

    string s;
    cout << "Enter String :";
    cin >> s;
    // -------------------------------------------------------
    // Palindrome Partition Function 
    vector<vector<string>> ans = PalindromePartition(s);
    // -------------------------------------------------------
    // Printing ans 
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]";
    }
    // --------------------------------------------------------
    return 0;
}