#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------
// Example:
// Input:
// n = 5
// arr = [1,2,3,4,5]

// Output:
// arr = [2,3,4,5,1]
// -----------------------------------------

vector<int> RotateArrayByOnePlace(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
}

// Time Complexity : O(N)
// Space Complexity :O(1)
// -------------------------------------------------

int main()
{

    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // -----------------------------------------
    RotateArrayByOnePlace(arr, n);
    // -----------------------------------------

    cout << "Output :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}