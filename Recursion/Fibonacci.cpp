#include <bits/stdc++.h>
using namespace std;

FibonacciFunction(int n)
{
    if (n <= 1)
        return n;
    int last = FibonacciFunction(n - 1);
    int secondLast = FibonacciFunction(n - 2);
    return last + secondLast;
}

int main()
{
    int n;
    cout << "Enter the Number :";
    cin >> n;
    cout << FibonacciFunction(n);

    return 0;
}