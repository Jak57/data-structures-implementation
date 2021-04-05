#include<bits/stdc++.h>
#define INF 100000000

using namespace std;

int main()
{
    int n, i, j, coin[100000], dp[100000], amount, id;
    cin>> n >> amount;

    for(i = 1; i <= n; i++)
        cin>> coin[i];

    dp[0] = 0;
    for(i = 1; i <= amount; i++)
        dp[i] = INF;

    for(i = 1; i <= amount; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(coin[j] > i)
                continue;

            id = i - coin[j];
            dp[i] = min(dp[i], dp[id]+1);
        }
    }

    cout<< dp[amount] << "\n";

    return 0;
}
/*
4 264
474 83 404 3
*/
