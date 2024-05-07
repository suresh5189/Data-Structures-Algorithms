// Example 1:
// Input:

// n = 5,m = 5.
// arr1[] = {1,2,3,4,5}
// arr2[] = {2,3,4,4,5}
// Output:

//  {1,2,3,4,5}

// Explanation:

// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1
// Distnict Elemennts in arr2 are : No distinct elements.
// Union of arr1 and arr2 is {1,2,3,4,5}

// Example 2:
// Input:

// n = 10,m = 7.
// arr1[] = {1,2,3,4,5,6,7,8,9,10}
// arr2[] = {2,3,4,4,5,11,12}
// Output:
//  {1,2,3,4,5,6,7,8,9,10,11,12}
// Explanation:

// Common Elements in arr1 and arr2  are:  2,3,4,5
// Distnict Elements in arr1 are : 1,6,7,8,9,10
// Distnict Elemennts in arr2 are : 11,12
// Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}

// --------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------------
// Brute Force Solution
vector<int> unionOfSortedArray(int arr1[], int arr2[], int m, int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(arr2[i]);
    }
    vector<int> un;
    for (auto it : st)
    {
        un.push_back(it);
    }

    return un;
}

// Time Complexity: O(n+m)
// -------------------------------------------------------------

// Optimal Solution
vector<int> unionOfSortedArray(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    vector<int> unionArr;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i])
                unionArr.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
                unionArr.push_back(arr2[j]);
            j++;
        }
    }
    while (j < m)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            unionArr.push_back(arr2[j]);
        j++;
    }
    while (i < n)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr1[i])
            unionArr.push_back(arr1[i]);
        i++;
    }

    return unionArr;
}

// Time Complexity: O(n+m)
// Space Complexity: O(n+m)
// ----------------------------------------------------------------
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

    // ----------------------------------------------
    vector<int> ans = unionOfSortedArray(arr1, arr2, m, n);
    // ----------------------------------------------

    cout << "Output :";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}