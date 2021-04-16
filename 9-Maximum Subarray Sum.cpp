#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, arr[100000], i, j, dp[100000], ans = 0;
    cin>> n;
    for (i = 1; i <= n; i++)
        cin>> arr[i];

    dp[1] = arr[1];
    for (i = 2; i <= n; i++)
        dp[i] = max(arr[i], arr[i] + dp[i-1]);

    for (i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
        cout<< dp[i] << " ";
    }
    cout<< "\n";
    cout<< ans << "\n";

    return 0;
}
/*
8
-1 -4 4 -2 0 1 4 -5
*/
