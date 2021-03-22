#include<bits/stdc++.h>
#define INF 10000000000

using namespace std;

typedef long long int ll;

ll arr[100001], st[400001];

ll query(ll i, ll L, ll R, ll qs, ll qe)
{
    ll mid, l, r;
    if(qs > R || qe < L){
        return INF;
    }

    if(L >= qs && R <= qe)
        return st[i];

    mid = (L+R)/2;

    l = query(2*i, L, mid, qs, qe);
    r = query(2*i+1, mid+1, R, qs, qe);

    return min(l, r);
}

void buildTree(ll i, ll L, ll R)
{

    if(L == R){
        st[i] = arr[L];
        return;
    }


    ll mid = (L+R)/2;

    buildTree(2*i, L, mid);
    buildTree(2*i + 1, mid+1, R);

    st[i] = min(st[2*i], st[2*i + 1]);

}

int main()
{
    ll n, i, j, q, qs, qe, ans;
    cin>> n;

    for(i = 1; i <= n; i++)
        cin>> arr[i];

    buildTree(1, 1, n);

    cin>> q;

    for(i = 1; i <= q; i++){
        cin>> qs >> qe;

        ans = query(1, 1, n, qs+1, qe+1);
        cout<< ans << "\n";
    }

    return 0;
}

