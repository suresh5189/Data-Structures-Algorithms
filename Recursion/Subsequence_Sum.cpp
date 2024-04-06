// Printing Subsequence whose sum is k

#include <bits/stdc++.h>
using namespace std;

void SubsequenceSum(int index, int arr[], vector<int> &ds, int sum, int s, int n)
{
    if (index == n)
    {
        if (sum == s)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[index]);
    s = s + arr[index];
    SubsequenceSum(index + 1, arr, ds, sum, s, n); // take
    s = s - arr[index];
    ds.pop_back();
    SubsequenceSum(index + 1, arr, ds, sum, s, n); // not take
}

int main()
{

    int n;
    cout << "Enter the Size of Array :";
    cin >> n;
    int arr[n];
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ds;
    int sum;
    cout << "Enter Sum Value :";
    cin >> sum;
    SubsequenceSum(0, arr, ds, sum, 0, n);

    return 0;
}