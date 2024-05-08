// Example 1:
// Input Format:
//  arr[] = {2,2,1}
// Result:
//  1
// Explanation:
//  In this array, only the element 1 appear once and so it is the answer

// Example 2:
// Input Format:
//  arr[] = {4,1,2,1,2}
// Result:
//  4
// Explanation:
//  In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer

// -------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------
// Brute Force Solution
int findTheNumberThatAppearsOnceAndThatOtherTwice(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }
    return -1;
}

// Time Complexity: O(N)+O(N)+O(N), where N = size of the array
// Reason: One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.
// Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
// ---------------------------------------------------------------------

// Optimal Solution
int findTheNumberThatAppearsOnceAndThatOtherTwice(int arr[], int n)
{
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

// Time Complexity: O(N), where N = size of the array.
// Reason: We are iterating the array only once.

// Space Complexity: O(1) as we are not using any extra space.
// ---------------------------------------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of Array1 :";
    cin >> n;
    int arr[n];
    cout << "Enter the Element in the Array1 :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // -------------------------------------------
    int ans = findTheNumberThatAppearsOnceAndThatOtherTwice(arr, n);
    // -------------------------------------------
    cout << "Output :" << ans << endl;
    return 0;
}