#include <bits/stdc++.h>
using namespace std;

// --------------------------------------
// Example:
// Input:
// n = 10
// arr = [1,0,2,3,2,0,0,4,5,1]

// Output:
// arr = [1,2,3,2,4,5,1,0,0,0]
// -----------------------------------------

void MoveAllZeroToTheEndOfTheArray(int arr[], int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    int tempSize = temp.size();
    for (int i = 0; i < tempSize; i++)
    {
        arr[i] = temp[i];
    }

    for (int i = tempSize; i < n; i++)
    {
        arr[i] = 0;
    }
}

// Time Complexity: O(n) + O(x) + O(n-x)
// Space Complexity: O(x)
// X = no. of non-zero elements, and N-X = total no. of zeros.
// -----------------------------------------------------------

// Optimal Solution
// Algorithm:
// First, using a loop, we will place the pointer j. If we don’t find any 0, we will not perform the following steps.
// After that, we will point i to index j+1 and start moving the pointer using a loop.
// While moving the pointer i, we will do the following:
// If a[i] != 0 i.e. a[i] is a non-zero element: We will swap a[i] and a[j]. Now, the current j is pointing to the non-zero element a[i]. So, we will shift the pointer j by 1 so that it can again point to the first zero.
// Finally, our array will be set in the right manner.

void MoveAllZeroToTheEndOfTheArray(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// ---------------------------------------

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int arr[n];
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // -------------------------------------------
    MoveAllZeroToTheEndOfTheArray(arr, n);
    // -------------------------------------------

    cout << "Output :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}