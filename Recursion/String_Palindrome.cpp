#include <bits/stdc++.h>
using namespace std;

bool StringPalindrome(int i, string &s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return StringPalindrome(i + 1, s);
}

int main()
{
    string s;
    cout << "Enter the String :";
    cin >> s;

    cout << StringPalindrome(0, s);
    return 0;
}