// Example 1:
// Input Format:
//  N = 5, array[] = {1,2,4,5}
// Result:
//  3
// Explanation:
// In the given array, number 3 is missing. So, 3 is the answer.

// Example 2:
// Input Format:
//  N = 3, array[] = {1,3}
// Result:
//  2
// Explanation:
// In the given array, number 2 is missing. So, 2 is the answer.

// -------------------------------------------------------------------

// Brute Force Solution
int findTheMissingNumber(int arr[], int n)
{
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    return 0;
}

// Time Complexity: (n*n)
// Space Complexity: O(1)
// -------------------------------------------------------------------

// Better Solution
int findTheMissingNumber(int arr[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
        {
            ans = i;
        }
    }
    return ans;
}

// Time Complexity: O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
// Space Complexity: O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.
// -------------------------------------------------------------------

// Optimal Solution 1
int findTheMissingNumber(int arr[], int n)
{
    int sum = (n * (n + 1)) / 2;
    int sum2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum2 = sum2 + arr[i];
    }
    return sum - sum2;
}

// Time Complexity: O(N), where N = size of array+1
// Space Complexity: O(1) as we are not using any extra space
// -------------------------------------------------------------------

// Example :
// Assume the given array is: {1, 2, 4, 5} and N = 5.
// XOR of (1 to 5) i.e. xor1 = (1^2^3^4^5)
// XOR of array elements i.e. xor2 = (1^2^4^5)
// XOR of xor1 and xor2 = (1^2^3^4^5) ^ (1^2^4^5)
// 			= (1^1)^(2^2)^(3)^(4^4)^(5^5)
// 			= 0^0^3^0^0 = 0^3 = 3.
// The missing number is 3.

// Optimal Solution 2
int findTheMissingNumber(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;
    int N = n - 1;
    for (int i = 0; i < N; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

// Time Complexity: O(N), where N = size of array+1
// Space Complexity: O(1) as we are not using any extra space
// -------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

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

    // ---------------------------------------------------
    int ans = findTheMissingNumber(arr, n);
    // ---------------------------------------------------
    cout << "The Missing Number is :" << ans << endl;
    return 0;
}