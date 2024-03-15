#include <bits/stdc++.h>
using namespace std;

// Brute Force Solution
//  void BubbleSort(int arr[], int n)
//  {
//      int temp = 0;
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = 0; j < n - i - 1; j++)
//          {
//              if (arr[j] > arr[j + 1])
//              {
//                  temp = arr[j];
//                  arr[j] = arr[j + 1];
//                  arr[j + 1] = temp;
//              }
//          }
//      }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// optimize Solution
void BubbleSort(int arr[], int n)
{
    int temp = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

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
    cout << "Enter the value in the Array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BubbleSort(arr, n);
    return 0;
}
