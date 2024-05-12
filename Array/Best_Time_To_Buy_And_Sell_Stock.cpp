#include <bits/stdc++.h>
using namespace std;

// ----------------------------
int bestTimeToBuyAndSellStock(vector<int> &prices, int n)
{
    int mini = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the Element in the Array :";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    // ------------------------------------------
    int profit = bestTimeToBuyAndSellStock(prices, n);
    // ------------------------------------------
    cout << "Output :" << profit << endl;
    return 0;
}