#include <bits/stdc++.h>
using namespace std;

bool findArrayIsSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            continue;
        }
        else
            return false;
    }
    return true;
}

// Time Complexity : O(N)
// -------------------------------------------

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

    bool isSorted = findArrayIsSorted(arr, n);

    if (isSorted)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}