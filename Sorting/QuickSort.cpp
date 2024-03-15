#include <bits/stdc++.h>
using namespace std;

// Selecting the Rightmost as the Pivot Element
// int Partition(vector<int> &arr, int low, int high)
// {
//     int pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// Selecting the Leftmost as the Pivot Element
int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[i] > pivot && j >= low + 1)
            j--;
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);

    return j;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partition = Partition(arr, low, high);
        QuickSort(arr, low, partition - 1);
        QuickSort(arr, partition + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}