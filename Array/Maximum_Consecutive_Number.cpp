// Example 1:
// Input: prices = {1, 1, 0, 1, 1, 1}
// Output: 3
// Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

// Input: prices = {1, 0, 1, 1, 0, 1}
// Output: 2
// Explanation: There are two consecutive 1's in the array.

// --------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int maximumConsecutiveNumber(int arr[], int n)
{
    int maxi = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maxi = max(count, maxi);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
}

// Time Complexity: O(N) since the solution involves only a single pass
// Space Complexity: O(1) because no extra space is used
// ---------------------------------------------------------

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

    // -----------------------------------------
    int ans = maximumConsecutiveNumber(arr, n);
    // -----------------------------------------
    cout << "Maximum Consecutive One's are :" << ans << endl;
    return 0;
}