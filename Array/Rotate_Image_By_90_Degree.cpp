// Example 1:
// Input:
//  [[1,2,3],[4,5,6],[7,8,9]]

// Output
// : [[7,4,1],[8,5,2],[9,6,3]]

// Explanation:
// Rotate the matrix simply by 90 degree clockwise and return the matrix.
// Input:
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 7 4 1
// 8 5 2
// 9 6 3

// Example 2:
// Input:
//  [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]

// Output:
// [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Explanation:
//  Rotate the matrix simply by 90 degree clockwise and return the matrix

// ----------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------------------

// Brute Force Solution
vector<vector<int>> rotateImageBy90Degree(vector<vector<int>> &matrix, int n)
{
    vector<vector<int>> result(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[j][n - i - 1] = matrix[i][j];
        }
    }
    return result;
}

// Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.
// Space Complexity: O(N*N) to copy it into some other matrix.
// ----------------------------------------------------------------------------

// Optimal Solution
vector<vector<int>> rotateImageBy90Degree(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

// Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
// Space Complexity: O(1).
// ----------------------------------------------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of the Matrix :";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the Element in the Matrix :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // -----------------------------------------
    vector<vector<int>> ans = rotateImageBy90Degree(matrix, n);
    // -----------------------------------------

    cout << "Matrix After 90 Degree Rotate :" << endl;
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
