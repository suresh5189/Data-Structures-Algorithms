// Given an integer array nums of unique elements, return all possible subsets(the power set).
// The solution set must not contain duplicate subsets.Return the solution in any order.

// Example 1 :
// Input : nums = [ 1, 2, 3 ]
// Output : [ [], [1], [2], [ 1, 2 ], [3], [ 1, 3 ], [ 2, 3 ], [ 1, 2, 3 ] ]

// Example 2 :
// Input : nums = [0]
// Output : [ [], [0] ]

// Constraints :

// 1 <= nums.length <= 10
// - 10 <= nums[i] <= 10
// All the numbers of nums are unique.

#include <bits/stdc++.h>
using namespace std;

void SubsetsFunction(int index, int arr[], vector<vector<int>> &ans, vector<int> &ds, int n)
{
    if (index == n)
    {
        ans.push_back(ds);
        return;
    }

    SubsetsFunction(index + 1, arr, ans, ds, n);
    ds.push_back(arr[index]);
    SubsetsFunction(index + 1, arr, ans, ds, n);
    ds.pop_back();
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int arr[n];
    cout << "Enter the Size of the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans;
    vector<int> ds;
    SubsetsFunction(0, arr, ans, ds, n);

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
    return 0;
}