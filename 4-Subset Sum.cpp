#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, sum, coin[10000], j, val;
    int ans[100][100];

    cin>> n >> sum;

    for(i = 1; i <= n; i++)
        cin>> coin[i];

    for(i = 0; i <= sum; i++)
        ans[0][i] = 0;

    ans[0][0] = 1;

    for(i = 1; i <= n; i++)
        ans[i][0] = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= sum; j++)
        {
            if(coin[i] > j)
                ans[i][j] = ans[i-1][j];
            else
            {
                val = coin[i];

                if(ans[i-1][j-val] > 0)
                    ans[i][j] = 1;
                else
                    ans[i][j] = ans[i-1][j];
            }
        }
    }


    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= sum; j++)
        {
            cout<< ans[i][j] << " ";
        }
        cout<< "\n";
    }

    return 0;
}
/*
4 12
2 5 3 4
*/
