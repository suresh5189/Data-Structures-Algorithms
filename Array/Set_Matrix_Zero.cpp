// Examples 1:
// Input:
//  matrix=[[1,1,1],[1,0,1],[1,1,1]]

// Output:
//  [[1,0,1],[0,0,0],[1,0,1]]

// Explanation:
//  Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

// Input:
//  matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]

// Output:
// [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Explanation:
// Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0

// -------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// Brute Force Solution

void markRow(vector<vector<int>> &arr, int i, int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

void markCol(vector<vector<int>> &arr, int j, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

vector<vector<int>> setMatrixZero(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                markRow(arr, i, n, m);
                markCol(arr, j, n, m);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}

// Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
// Another O(N*M) is taken to mark all the cells with -1 as 0 finally.

// Space Complexity: O(1) as we are not using any extra space.
// -----------------------------------------------------------------------------------

// Better Solution
vector<vector<int>> setMatrixZero(vector<vector<int>> &arr, int n, int m)
{
    int row[n] = {0};
    int col[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}

// Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

// Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: O(N) is for using the row array and O(M) is for using the col array.
// --------------------------------------------------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of Row :";
    cin >> n;
    int m;
    cout << "Enter the Size of Column :";
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter the Element in the Matrix :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // ---------------------------------------
    vector<vector<int>> ans = setMatrixZero(arr, n, m);
    // ---------------------------------------

    cout << "The Final Set Matrix Is :" << endl;
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