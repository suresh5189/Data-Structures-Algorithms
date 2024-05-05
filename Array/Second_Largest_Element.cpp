#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
int getSecondLargestElement(int arr[], int n)
{
    int largest = arr[n - 1];
    int secondLargest = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            secondLargest = arr[i];
            break;
        }
    }
    return secondLargest;
}

// Time Complexity : O(NlogN) + O(N)
// --------------------------------------------

// Better Solution
int getSecondLargestElement(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    int secondLargest = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// Time Complexity : O(N) + O(N)
// ------------------------------------------------

// Optimal Solution
int getSecondLargestElement(int arr[], int n)
{
    int largest = arr[0];
    int secondLargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// Time Complexity : O(N)
// -------------------------------------------------

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
    // ---------------------------------------
    // Sorting the Array
    sort(arr, arr + n);
    // ---------------------------------------

    int secondLargestElement = getSecondLargestElement(arr, n);

    cout << "Second Largest Element :" << secondLargestElement << endl;

    return 0;
}