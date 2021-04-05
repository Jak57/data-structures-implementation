1.
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

2.
// Another Approach O(m) memory:

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, sum, coin[10000], dp[100000], val;
    cin>> n >> sum;

    for(i = 1; i <= n; i++)
        cin>> coin[i];

    dp[0] = 1;
    for(i = 1; i <= sum; i++)
        dp[i] = 0;

    for(i = 1; i <= n; i++)
    {

        for(j = sum; j >= coin[i]; j--)
        {
            if(dp[j] == 0)
            {
                val = coin[i];
                if(dp[j-val] != 0)
                    dp[j] = 1;
            }

        }
    }

    for(i = 0; i <= sum; i++)
        cout<< dp[i] << " ";
    cout<< "\n";


    return 0;
}
/*
4 12
2 5 3 4
*/
3. 
// Printing solution

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, sum, coin[10000], dp[100000], val;
    cin>> n >> sum;

    for(i = 1; i <= n; i++)
        cin>> coin[i];

    dp[0] = 1;
    for(i = 1; i <= sum; i++)
        dp[i] = 0;

    for(i = 1; i <= n; i++)
    {

        for(j = sum; j >= coin[i]; j--)
        {
            if(dp[j] == 0)
            {
                val = coin[i];
                if(dp[j-val] != 0)
                    dp[j] = coin[i];
            }

        }
    }

    i = sum;
    while(i > 0)
    {
        cout<< dp[i] << " ";
        i = i - dp[i];
    }


    return 0;
}
/*
4 12
2 5 3 4
*/





