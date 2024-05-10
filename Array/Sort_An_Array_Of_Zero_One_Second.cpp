// Input:
//  nums = [2,0,2,1,1,0]
// Output
// : [0,0,1,1,2,2]

// Input:
//  nums = [2,0,1]
// Output:
//  [0,1,2]

// Input:
//  nums = [0]
// Output:
//  [0]

// ---------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------------------

// Brute Force Solution
vector<int> sortAnArray(vector<int> &arr, int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    for (int i = 0; i < cnt0; i++)
    {
        arr[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        arr[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < n; i++)
    {
        arr[i] = 2;
    }
    return arr;
}

// Time Complexity: O(N) + O(N), where N = size of the array.
// First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.

// Space Complexity: O(1) as we are not using any extra space.
// -------------------------------------------

// Optimal Solution
vector<int> sortAnArray(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}

// Time Complexity: O(N), where N = size of the given array.
// Reason: We are using a single loop that can run at most N times.

// Space Complexity: O(1) as we are not using any extra space.
// -----------------------------------------------

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

    // --------------------------------
    vector<int> result = sortAnArray(arr, n);
    // --------------------------------

    cout << "Output :";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}