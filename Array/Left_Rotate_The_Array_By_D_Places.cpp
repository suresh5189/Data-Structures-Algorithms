#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------
// Example 1:
// Input: N = 7, array[] = {1,2,3,4,5,6,7} , d = 3
// Output: 4 5 6 7 1 2 3
// Explanation: The array is rotated to the left by 3 positions.

// Example 2:
// Input: N = 6, array[] = {3,7,8,9,10,11} , d = 2
// Output: 8 9 10 11 3 7
// Explanation: The array is rotated to the left by 2 positions.
// -------------------------------------------

// Brute Force Solution
void LeftRotateTheArrayByOnePlace(int arr[], int n, int d)
{
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

// Time Complexity: (n+d)
// Space Complexity : O(d)
// -------------------------------------------------

// Optimized Approach(without using any extra space): Using “Reversal Algorithm”
// This is a straightforward method. The steps are as follows:

// Step 1: Reverse the subarray with the first d elements (reverse(arr, arr+d)).
// Step 2: Reverse the subarray with the last (n-d) elements (reverse(arr+d, arr+n)).
// Step 3: Finally reverse the whole array (reverse(arr, arr+n)).

void LeftRotateTheArrayByOnePlace(int arr[], int n, int d)
{
    if (n == 0)
        return;

    d = d % n;

    reverse(arr, arr + d);     // TC => O(d)
    reverse(arr + d, arr + n); // TC => O(n-d)
    reverse(arr, arr + n);     // TC => O(n)
}

// Time Complexity: O(d) + O(n-d) + O(n)
// Space Complexity: O(1)
// ----------------------------------------------------------------

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
    int d;
    cout << "Enter the Position By which to Rotate the Array :";
    cin >> d;

    // -------------------------------------------
    LeftRotateTheArrayByOnePlace(arr, n, d);
    // -------------------------------------------

    cout << "Output :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}