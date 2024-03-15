#include <bits/stdc++.h>
using namespace std;

// Time Complexity : Ο(n log n)

void Merge(int arr[], int low, int mid, int high)
{
    int b[5];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
            b[k] = arr[j++];
        else
            b[k] = arr[i++];
        k++;
    }

    while (i <= mid)
    {
        b[k++] = arr[i++];
    }

    while (j <= high)
    {
        b[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}

void MergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
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
    int low = 0, high = n - 1;

    // ------- MergeSort Funtction -------------
    MergeSort(arr, low, high);

    cout << "Output :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}