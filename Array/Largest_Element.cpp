#include <bits/stdc++.h>
using namespace std;

int getLargestElement(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

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
    // ---------------------------------------------------
    int largest = getLargestElement(arr, n);
    cout << "Largest Element :" << largest << endl;
    // ---------------------------------------------------

    return 0;
}

// Time Complexity - O(n)