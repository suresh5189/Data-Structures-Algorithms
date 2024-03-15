#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n+k)
// n => size of Input Array
// k => size of Output Array

void CountingSort(int arr[], int n)
{
    int output[n];
    int count[n];
    int max = arr[0];

    // Finding the Largest Element from the Array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Intializing the Count Array with zero
    for (int i = 0; i <= n; i++)
    {
        count[i] = 0;
    }

    // Store the Count of each Element
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Store the Cummulative Count of Each Array
    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Creating outputArray[] from countArray[] array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int arr[n];
    cout << "Enter the element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    CountingSort(arr, n);

    cout << "Output :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}