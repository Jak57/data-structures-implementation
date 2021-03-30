#include<bits/stdc++.h>
#define mod 1000000007
#define MAX 1000001

using namespace std;

int dp[MAX];

int main()
{
    int n, i;
    dp[1] = 1;
    dp[2] = 2;
    cin>> n;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
        cout<< dp[i] << "\n";
    }

    return 0;
}
