// Example 1:
// Input:
//  arr = [-2,1,-3,4,-1,2,1,-5,4]

// Output:
//  6

// Explanation:
//  [4,-1,2,1] has the largest sum = 6.

// Examples 2:
// Input:
//  arr = [1]

// Output:
//  1

// Explanation:
//  Array has only one element and which is giving positive sum of 1.

// --------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------

// Brute Force Solution
int maximumSubArraySum(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
                maxi = max(maxi, sum);
            }
        }
    }
    return maxi;
}

// Time Complexity: O(N^3), where N = size of the array.
// Reason: We are using three nested loops, each running approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
// ----------------------------------------------------------------------

// Better Solution
int maximumSubArraySum(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// Time Complexity: O(N^2), where N = size of the array.
// Reason: We are using two nested loops, each running approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
// -----------------------------------------------------------------------

// Optimal Solution (Kadane's Algorithm)
int maximumSubArraySum(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

// ---------------------
// Follow Up Question (Kadane's Algorithm)

int maximumSubArraySum(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum = sum + arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
            sum = 0;
    }
    // -----------------------------------
    cout << "The Subarray Is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]"<<endl;
    // -----------------------------------
    return maxi;
}

// Time Complexity: O(N), where N = size of the array.
// Reason: We are using a single loop running N times.

// Space Complexity: O(1) as we are not using any extra space.
// ------------------------------------------------------------------------

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

    // --------------------------------------------
    int ans = maximumSubArraySum(arr, n);
    // --------------------------------------------
    cout << "The Maximum Subarray Sum Is :" << ans << endl;
    return 0;
}