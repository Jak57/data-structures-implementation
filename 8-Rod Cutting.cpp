#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p[100000], n, i, j, profit, dp[100000];
    cin>> n;

    for (i = 1; i <= n; i++)
        cin>> p[i];

    dp[0] = 0;
    for (i = 1; i <= n; i++)
    {
        profit = 0;
        for (j = 1; j <= i; j++)
            profit = max(profit, p[j] + dp[i-j]);

        dp[i] = profit;
    }

    for (i = 1; i <= n; i++)
        cout<< dp[i] << " ";
    cout<< "\n";

    return 0;
}
/*
10
1 5 8 9 10 17 17 20 24 30
*/
