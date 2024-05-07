// Example 1:
// Input:
// A: [1 2 3 3 4 5 6]
// B: [3 3 5]
// Output: 3,3,5
// Explanation: We are given two arrays A and B.
// The elements present in both the arrays
// are 3,3 and 5.

// Example 2:
// Input:
// A: [1 2 3 3 4 5 6]
// B: [3 5]
// Output: 3,5
// Explanation: We are given two arrays A and B.
// The elements present in both the arrays are 3 and 5.

// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------------------
// Brute Force Solution
vector<int> intersectionOfTwoSortedArray(int arr1[], int arr2[], int m, int n)
{
    vector<int> result;
    int vis[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j] && vis[j] == 0)
            {
                result.push_back(arr2[j]);
                vis[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }
    return result;
}

// Time Complexity: O(n*m)
// Space Complexity: O(n)
// ---------------------------------------------------------------------------

// Optimal Solution
vector<int> intersectionOfTwoSortedArray(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    vector<int> result;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            result.push_back(arr2[j]);
            i++;
            j++;
        }
    }
    return result;
}

// Time Complexity: O(n)
// Since the elements are compared within the single pass for both the arrays this approach would take a linear time and in the worst case O(n1+n2) where n1 = A.size() and n2 = B.size()
// Space Complexity: O(1)
// ---------------------------------------------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of Array1 :";
    cin >> n;
    int arr1[n];
    cout << "Enter the Element in the Array1 :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the Size of Array2 :";
    cin >> m;
    int arr2[m];
    cout << "Enter the Element in the Array2 :";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    // --------------------------------------
    vector<int> ans = intersectionOfTwoSortedArray(arr1, arr2, m, n);
    // --------------------------------------

    cout << "Output :";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}