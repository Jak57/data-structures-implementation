//Help Ashu (HackerEarth)

#include<bits/stdc++.h>

using namespace std;

int arr[100001], st[400001];

int query(int i, int L, int R, int qs,int qe)
{
    int mid, l, r;

    if(qe < L || R < qs)
        return 0;

    if(qs <= L && R <= qe)
        return st[i];

    mid = (L+R)/2;

    l = query(2*i, L, mid, qs, qe);
    r = query(2*i + 1, mid+1, R, qs, qe);

    //st[i] = st[2*i] + st[2*i + 1];

    return l+r;

}

void update(int i, int L, int R, int qi)
{
    if(L == R){
        if(arr[L] % 2 == 0)
            st[i] = 1;
        else
            st[i] = 0;

        return;
    }

    int mid = (L+R)/2;

    if(qi <= mid)
        update(2*i, L, mid, qi);
    else
        update(2*i + 1, mid+1, R, qi);

    st[i] = st[2*i] + st[2*i + 1];
}

void buildTree(int i, int L, int R)
{
    if(L == R){
        if(arr[L] % 2 == 0)
            st[i] = 1;
        else
            st[i] = 0;

        return;
    }

    int mid = (L+R)/2;

    buildTree(2*i, L, mid);
    buildTree(2*i + 1, mid+1, R);

    st[i] = st[2*i] + st[2*i + 1];
}

int main()
{
    int n, i, j, q, a, x, y, ans;
    cin>> n;

    for(i = 1; i <= n; i++)
        cin>> arr[i];

    buildTree(1, 1, n);

    cin>> q;
    for(j = 1; j <= q; j++){
        cin>> a >> x >> y;

        //ans = query(1, 1, n, x, y);
        //cout<< ans << "\n";

        if(a == 0){
            if((arr[x] % 2) == (y % 2))
                continue;

            arr[x] = y;
            update(1, 1, n, x);
        }
        else{
            ans = query(1, 1, n, x, y);
            if(a == 1)
                cout<< ans << "\n";
            else
                cout<< (int)abs(y - x + 1 - ans) << "\n";

        }
    }

    return 0;
}
/*
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
*/
