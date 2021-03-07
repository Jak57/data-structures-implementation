#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll f[1000001];

ll C(ll n, ll k)
{
    ll res = 1;
    if(k > n-k)
        k = n-k;

    for(ll i = 1; i <= k; i++){
       res *= (n-i+1);
       res /= i;
    }
    return res;
}

int main()
{
    ll n, k, i, j, t;
    cin>> t;

    for(i = 1; i <= t; i++){
        cin>> n >> k;
        cout<< C(n-1, k-1) << "\n";
    }

    return 0;
}
