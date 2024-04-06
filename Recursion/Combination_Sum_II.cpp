// Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.
// Note : The solution set must not contain duplicate combinations.

// Example 1 :
// Input : candidates = [ 10, 1, 2, 7, 6, 1, 5 ],
//         target = 8
//         Output : [[ 1, 1, 6 ],[ 1, 2, 5 ],[ 1, 7 ],[ 2, 6 ]]

// Example 2 :
// Input : candidates = [ 2, 5, 2, 1, 2 ],
//         target = 5
//         Output : [[ 1, 2, 2 ],[5]]

// Constraints :
// 1 <= candidates.length<= 100
// 1 <= candidates[i] <= 50
// 1 <= target<= 30

#include <bits/stdc++.h>
using namespace std;

void SumCombination(int index, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int target)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        SumCombination(i + 1, arr, ans, ds, target - arr[i]);
        ds.pop_back();
    }
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
    // -----------------------------------------
    SumCombination(0, arr, ans, ds, target);
    // -----------------------------------------
    sort(arr.begin(), arr.end());
    // -----------------------------------------
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