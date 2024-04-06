// Given an array nums of distinct integers, return all the possible permutations.You can return the answer in any order.

// Example 1 :
// Input : nums = [ 1, 2, 3 ]
// Output : [ [ 1, 2, 3 ], [ 1, 3, 2 ], [ 2, 1, 3 ], [ 2, 3, 1 ], [ 3, 1, 2 ], [ 3, 2, 1 ] ]

// Example 2 :
// Input : nums = [ 0, 1 ]
// Output : [ [ 0, 1 ], [ 1, 0 ] ]

// Example 3 :
// Input : nums = [1]
// Output : [[1]]

// Constraints :
// 1 <= nums.length <= 6
// - 10 <= nums[i] <= 10
// All the integers of nums are unique.

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------
// Approach 1
void PermutationFunction(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &freq)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            PermutationFunction(nums, ds, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

// -----------------------------------------

// Approach 2
void PermutationFunction(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i= index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        PermutationFunction(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }
    vector<int> ds;
    vector<vector<int>> ans;
    // -----------------------------------------------------------
    // Approach 1
    // PermutationFunction(nums, ds, ans, freq);
    // -----------------------------------------------------------
    // Approach 2
    PermutationFunction(0, nums, ans);
    // -----------------------------------------------------------
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]";
    }
    // -----------------------------------------------------------
    return 0;
}