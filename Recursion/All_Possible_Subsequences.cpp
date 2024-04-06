#include <bits/stdc++.h>
using namespace std;

void PrintSubsequence(int index, int arr[], vector<int> &ds, int n)
{
    if (index == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    ds.push_back(arr[index]);
    PrintSubsequence(index + 1, arr, ds, n);
    ds.pop_back();
    PrintSubsequence(index + 1, arr, ds, n);
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int arr[n];
    vector<int> ds;
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    PrintSubsequence(0, arr, ds, n);

    return 0;
}