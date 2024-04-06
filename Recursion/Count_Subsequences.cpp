// Count the Subsequences Whose Sum is Equal to k

#include <bits/stdc++.h>
using namespace std;

int CountSubsequences(int index, int arr[], int sum, int s, int n)
{
    if (index == n)
    {
        if (sum == s)
        {
            return 1;
        }
        else
            return 0;
    }

    s = s + arr[index];
    int left = CountSubsequences(index + 1, arr, sum, s, n);
    s = s - arr[index];
    int right = CountSubsequences(index + 1, arr, sum, s, n);

    return (left + right);
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int arr[n];
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cout << "Enter the Value of Sum :";
    cin >> sum;
    cout << CountSubsequences(0, arr, sum, 0, n);

    return 0;
}