#include <bits/stdc++.h>
using namespace std;

int PalindromeFunction(int n, int temp)
{
    if (n == 0)
        return temp;
    temp = (temp * 10) + (n % 10);
    return PalindromeFunction(n / 10, temp);
}

int main()
{
    int n;
    cout << "Enter the Number :";
    cin >> n;
    int temp = PalindromeFunction(n, 0);
    if (n == temp)
    {
        cout << "The Number is Palindrome" << endl;
    }
    else
    {
        cout << "The Number is Not Palindrome" << endl;
    }
    return 0;
}

// Example: Number = 121
//  temp = 0;

// n % 10 = 1
// n % 10 = 2
// n % 10 = 1

// int temp = temp * 10 + 1 = 1 * 0 +1 = 1
// temp = 1 * 10 + 2 = 12
// temp = 12 * 10 + 1 = 121
