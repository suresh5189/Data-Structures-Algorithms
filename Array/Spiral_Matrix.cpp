// Example 1:
// Input: Matrix[][] = { { 1, 2, 3, 4 },
// 		      { 5, 6, 7, 8 },
// 		      { 9, 10, 11, 12 },
// 	              { 13, 14, 15, 16 } }

// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

// Example 2:
// Input: Matrix[][] = { { 1, 2, 3 },
// 	              { 4, 5, 6 },
// 		      { 7, 8, 9 } }

// Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
// Explanation: The output of matrix in spiral form.

// --------------------------------------------------------------

// In this approach, we will be using four loops to print all four sides of the matrix.

// 1st loop: This will print the elements from left to right.

// 2nd loop: This will print the elements from top to bottom.

// 3rd loop: This will print the elements from right to left.

// 4th loop: This will print the elements from bottom to top.

// Steps:

// Create and initialize variables top as starting row index, bottom as ending row index left as starting column index, and right as ending column index. As shown in the image given below.

// 1. In each outer loop traversal print the elements of a square in a clockwise manner.
// 2. Print the top row, i.e. Print the elements of the top row from column index left to right and increase the count of the top so that it will move to the next row.
// 3. Print the right column, i.e. Print the rightmost column from row index top to bottom and decrease the count of right.
// 4. Print the bottom row, i.e. if top <= bottom, then print the elements of a bottom row from column right to left and decrease the count of bottom
// 5. Print the left column, i.e. if left <= right, then print the elements of the left column from the bottom row to the top row and increase the count of left.
// 6. Run a loop until all the squares of loops are printed.

// Note: As we can see in the code snippet below, two edge conditions are being added in the last two ‘for’ loops: when we are moving from right to left and from bottom to top.

// These conditions are added to check if the matrix is a single column or a single row. So, whenever the elements in a single row are traversed they cannot be traversed again backward so the condition is checked in the right-to-left loop. When a single column is present, the condition is checked in the bottom-to-top loop as elements from bottom to top cannot be traversed again.

// -----------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------

vector<int> spiralMatrix(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> result;
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            result.push_back(matrix[bottom][i]);
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            result.push_back(matrix[i][left]);
        }
        left++;
    }
    return result;
}

// Time Complexity: O(m x n) { Since all the elements are being traversed once and there are total n x m elements ( m elements in each row and total n rows) so the time complexity will be O(n x m)}.
// Space Complexity: O(n) { Extra Space used for storing traversal in the ans array }.
// --------------------------------------------------------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of Row :";
    cin >> n;
    int m;
    cout << "Enter the Size of Column :";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the Element in the Matrix :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // ---------------------------------------
    vector<int> ans = spiralMatrix(matrix, n, m);
    // ---------------------------------------
    cout << "Spiral Matrix Output :" << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}