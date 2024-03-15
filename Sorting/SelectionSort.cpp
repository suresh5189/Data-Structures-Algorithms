#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
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
    SelectionSort(arr, n);
    return 0;
}