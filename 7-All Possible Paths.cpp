// Unique ways to reach (n, m) from (1, 1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dp[100][100], i, n, j, m;
    cin>> n >> m;

    for (i = 1; i <= m; i++)
        dp[n][i] = 1;

    for (j = 1; j <= n; j++)
        dp[j][m] = 1;

    for (i = n-1; i >= 1; i--)
    {
        for (j = m-1; j >= 1; j--)
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cout<< dp[i][j] << " ";

        cout<< "\n";
    }

    return 0;
}
