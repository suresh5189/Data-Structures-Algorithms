// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
// Result: 3
// Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.

// --------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------

// Brute Force Solution
int longestSubArrayWithSumK(int arr[], int n, int k)
{
    int sum = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
            }
            if (sum == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Time Complexity: O(N^3) approx., where N = size of the array.
// Reason: We are using three nested loops, each running approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
// ---------------------------------------------------------------

// Good Solution

int longestSubArrayWithSumK(int arr[], int n, int k)
{
    int sum = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (sum == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Time Complexity: O(N2) approx., where N = size of the array.
// Reason: We are using two nested loops, each running approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
// ----------------------------------------------------------------

// Better Solution
int longestSubArrayWithSumK(int arr[], int n, int k)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = k - sum;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

// Space Complexity: O(N) as we are using a map data structure.

// ----------------------------------------------------------------

// Optimal Solution
int longestSubArrayWithSumK(int arr[], int n, int k)
{
    int left = 0, right = 0;
    int maxLen = 0;
    long long sum = arr[0];
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum = sum - arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum = sum + arr[right];
    }
    return maxLen;
}

// Time Complexity: O(2*N), where N = size of the given array.
// Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).

// Space Complexity: O(1) as we are not using any extra space.
// -----------------------------------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int k;
    cout << "Enter the Value of K :";
    cin >> k;
    int arr[n];
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // ------------------------------------------------
    int ans = longestSubArrayWithSumK(arr, n, k);
    // ------------------------------------------------
    cout << "The length of the longest subarray is :" << ans << endl;
    return 0;
}