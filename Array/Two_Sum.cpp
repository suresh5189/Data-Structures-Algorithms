// Example 1:
// Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
// Result: YES (for 1st variant)
//        [1, 3] (for 2nd variant)
// Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

// Example 2:
// Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
// Result: NO (for 1st variant)
// 	[-1, -1] (for 2nd variant)
// Explanation: There exist no such two numbers whose sum is equal to the target.

// ----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------

// Brute Force Solution
// (Variant 1)
// string twoSum(vector<int> &arr, int target, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] + arr[j] == target)
//                 return "YES";
//         }
//     }
//     return "NO";
// }

// --------------

// (Variant 2)
// vector<int> twoSum(vector<int> &arr, int target, int n)
// {
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] + arr[j] == target)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return {-1, -1};
// }

// Time Complexity: O(N2), where N = size of the array.
// Reason: There are two loops(i.e. nested) each running for approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
// ---------------------------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int target;
    cout << "Enter the Value of Target :";
    cin >> target;
    vector<int> arr(n);
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // -----------------------------------
    // string ans = twoSum(arr, target, n); //Variant 1
    // cout << "Sum Pair Exist in the Array? :" << ans << endl;
    // -----------------------------------

    vector<int> result = twoSum(arr, target, n);
    cout << "This is the answer for variant 2: [" << result[0] << ", " << result[1] << "]" << endl;
    // ------------------------------------
    return 0;
}