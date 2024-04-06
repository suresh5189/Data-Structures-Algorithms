#include <bits/stdc++.h>
using namespace std;

// Time Complexity : -
// Best : O(n)
// Worst : O(n^2)
// Average : O(n^2)

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] >= temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "Output :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    int arr[n];
    cout << "Enter the value in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    InsertionSort(arr, n);
    return 0;
}