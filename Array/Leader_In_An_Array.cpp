// Example 1:
// Input:
//  arr = [4, 7, 1, 0]
// Output: 7 1 0
// Explanation:
//  Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

// Example 2:
// Input:
//  arr = [10, 22, 12, 3, 0, 6]
// Output: 22 12 6
// Explanation:
//  6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.

// ------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------

// Brute Force Solution
vector<int> leaderInAnArray(vector<int> &arr, int n)
{
    bool leader = true;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
            result.push_back(arr[i]);
    }
    return result;
}

// Time Complexity: O(N^2) { Since there are nested loops being used, at the worst case n^2 time would be consumed }.
// Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
// ---------------------------------------------------------

// Optimal Solution
vector<int> leaderInAnArray(vector<int> &arr, int n)
{
    int maxi = arr[n - 1];
    vector<int> result;
    result.push_back(arr[n - 1]);
    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i] > maxi)
        {
            result.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    return result;
}

// Time Complexity: O(N) { Since the array is traversed single time back to front, it will consume O(N) of time where N = size of the array }.

// Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
// ---------------------------------------------------------

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
    // -------------------------------------------
    vector<int> ans = leaderInAnArray(arr, n);
    // -------------------------------------------
    cout << "Resultant Array :" << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";
    // -------------------------------------------
    return 0;
}