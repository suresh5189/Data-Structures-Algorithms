#include <bits/stdc++.h>
using namespace std;

int FactorialFunction(int n)
{
    if (n == 0)
        return 1;
    return n * FactorialFunction(n - 1);
}

int main()
{
    int n;
    cout << "Enter the Number :";
    cin >> n;
    cout << FactorialFunction(n);

    return 0;
}