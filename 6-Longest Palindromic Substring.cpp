#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dp[100][100];
    int n, i, j, id, x, y;
    string s;
    cin>> s;
    n = s.size();

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
            dp[i][j] = 0;
    }

    for (i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    dp[1][0] = 0;

    for (i = 2; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (s[j - i + 1-1] == s[j-1]) // 0-based indexing in string
            {
                if (dp[i-2][j-1] == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }

        }
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (dp[i][j] == 1)
            {
                x = i;
                y = j;
            }
        }


    }

    cout<< x << "\n";
    id = (y - x + 1) - 1;
    for (i = 0; i < x; i++)
    {
        cout<< s[id];
        id++;
    }

    cout<< "\n";


    return 0;
}

// ABBCBBCA
