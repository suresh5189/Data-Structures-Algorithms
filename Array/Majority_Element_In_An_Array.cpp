// Example 1:
// Input Format
// : N = 3, nums[] = {3,2,3}
// Result
// : 3
// Explanation
// : When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution.

// Example 2:
// Input Format:
//   N = 7, nums[] = {2,2,1,1,1,2,2}
// Result
// : 2
// Explanation
// : After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

// Example 3:
// Input Format:
//   N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}
// Result
// : 4

// -------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// Brute Force Solution
int majorityElementInAnArray(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                cnt++;
        }
        if (cnt / 2)
            return arr[i];
    }
    return -1;
}

// Time Complexity: O(N^2), where N = size of the given array.
// Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2).
// Space Complexity: O(1) as we use no extra space.
// ---------------------------------------------------------

// Better Solution (Hashing)
int majorityElementInAnArray(int arr[], int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > n / 2)
            return it.first;
    }
    return -1;
}

// Time Complexity: O(N*logN) + O(N), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

// Space Complexity: O(N) as we are using a map data structure.
// --------------------------------------------------------------

// Optimal Solution (Moore's Voting Algorithm)
int majorityElementInAnArray(int arr[], int n)
{
    int element;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = arr[i];
        }
        else if (arr[i] == element)
            count++;
        else
            count--;
    }
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            count1++;
    }
    if (count1 > n / 2)
        return element;
    return -1;
}

// Time Complexity: O(N) + O(N), where N = size of the given array.
// Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.

// Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).

// Space Complexity: O(1) as we are not using any extra space.
// --------------------------------------------------------------

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

    // ----------------------------------------------------------
    int ans = majorityElementInAnArray(arr, n);
    // ----------------------------------------------------------
    cout << "The Majority Element is :" << ans << endl;
    return 0;
}