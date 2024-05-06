#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Example:
// Input:
// n = 5
// arr = [1,1,2,3,3,4]

// Output:
// arr = [1,2,3,4]
// --------------------------------------------

// Brute Force Solution
vector<int> RemoveDuplicatesFromSortedArray(vector<int> &arr, int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int index = 0;
    vector<int> result(st.begin(), st.end());
    return result;
}

// Time Complexity : O(NlongN) + O(N)
// Space Complexity : O(N)
// -------------------------------------------------

// Optimal Solution (2 Pointer)
int RemoveDuplicatesFromSortedArray(vector<int> &arr, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

// Time Complexity : O(N)
// Space Complexity : (1)
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

    // -----------------------------------------------------
    // Brute Force Solution
    arr = RemoveDuplicatesFromSortedArray(arr, n);
    // -----------------------------------------------------
    // Optimal Solution
    int m = RemoveDuplicatesFromSortedArray(arr, n);

    cout << "Output :";
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}