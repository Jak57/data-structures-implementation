#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

vector<int> st[4*MAX];
int arr[MAX];

int query(int i, int L, int R, int qs, int qe, int k)
{
    int mid, l, r, ans;

    if(qe < L || R < qs)
        return 0;

    if(qs <= L && R <= qe){
        ans = upper_bound(st[i].begin(), st[i].end(), k-1) - st[i].begin();
        return ans;
    }

    mid = (L+R)/2;
    l = query(2*i, L, mid, qs, qe, k);
    r = query(2*i+1, mid+1, R, qs, qe, k);

    return l+r;
}

void buildTree(int i, int L, int R)
{
    if(L == R){
        st[i].push_back(arr[L]);
        return;
    }

    int mid = (L+R)/2;
    buildTree(2*i, L, mid);
    buildTree(2*i+1, mid+1, R);

    int j = 0, k = 0, n, m, a, b;
    n = st[2*i].size();
    m = st[2*i+1].size();

    while(j < n && k < m){
        a = st[2*i][j];
        b = st[2*i+1][k];

        if(a <= b){
            st[i].push_back(a);
            j++;
        }
        else{
            st[i].push_back(b);
            k++;
        }

    }

    while(j < n){
        st[i].push_back(st[2*i][j]);
        j++;
    }

    while(k < m){
        st[i].push_back(st[2*i+1][k]);
        k++;
    }
}

int main()
{
    int n, i, j, q, qs, qe, k, ans;
    cin>> n;

    for(i = 1; i <= n; i++)
        cin>> arr[i];

    buildTree(1, 1, n);

    cin>> q;

    for(j = 1; j <= q; j++){
        cin>> qs >> qe >> k;

        ans = query(1, 1, n, qs, qe, k);
        cout<< ans << "\n";
    }

    return 0;
}

/*
8
1 4 3 5 6 4 3 2
1
3 7 4
*/
