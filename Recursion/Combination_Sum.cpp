// Combination Sum

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

// Constraints:
// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40

// -----------------------------------

// Time Complexity : O(2 ^ t * k) where t is the target, k is the average length of every combination generated
// Space Complexity : O(k *x), k is the average length and x is the no.of combinations

// ------------------------------------

#include <bits/stdc++.h>
using namespace std;

void CombinationSum(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int target, int n)
{
    if (index == n)
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        CombinationSum(index, arr, ds, ans, target - arr[index], n);
        ds.pop_back();
    }
    CombinationSum(index + 1, arr, ds, ans, target, n);
}

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
    int target;
    cout << "Enter the Value of Target :";
    cin >> target;
    vector<int> ds;
    vector<vector<int>> ans;
    CombinationSum(0, arr, ds, ans, target, n);
    // ---------------------------------------------
    cout << "Combination are :" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
                cout << ",";
        }
        cout << "]";
    }
    // ----------------------------------------------
    return 0;
}