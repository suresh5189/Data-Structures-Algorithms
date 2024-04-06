// Printing only one Subsequence whose sum is equal to k

#include <bits/stdc++.h>
using namespace std;

bool OneSubsequenceSum(int index, int arr[], vector<int> &ds, int sum, int s, int n)
{
    if (index == n)
    {
        if (sum == s)
        {
            for (auto it : ds)
                cout << it << " ";
            return true;
        }
        else
            return false;
    }

    ds.push_back(arr[index]);
    s = s + arr[index];
    if (OneSubsequenceSum(index + 1, arr, ds, sum, s, n) == true)
    {
        return true;
    }
    s = s - arr[index];
    ds.pop_back();
    if (OneSubsequenceSum(index + 1, arr, ds, sum, s, n) == true)
    {
        return true;
    }
    return false;
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
    int sum = 0;
    cout << "Enter the Value of Sum :";
    cin >> sum;
    vector<int> ds;
    OneSubsequenceSum(0, arr, ds, sum, 0, n);
    return 0;
}