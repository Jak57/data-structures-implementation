#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int arr[MAX], st[4*MAX], lt[4*MAX];

int query(int i, int L, int R, int qs, int qe)
{
    int mid, l, r, val;

    if(qe < L || R < qs)
        return 0;

    if(qs <= L && R <= qe){

        val = lt[i];

        if(lt[i] != 0){
            st[i] += (val * (R-L+1));
            lt[i] = 0;

            if(L != R){
               lt[2*i] = val;
               lt[2*i + 1] = val;
            }

        }

        return st[i];
    }

    mid = (L+R)/2;
    l = query(2*i, L, mid, qs, qe);
    r = query(2*i + 1, mid+1, R, qs, qe);

    return l+r;
}

void rangeUpdate(int i, int L, int R, int qs, int qe, int val)
{
    if(qe < L || R < qs)
        return;

    if(qs <= L && R <= qe){
        st[i] += (val * (R-L+1));

        if(L != R){
            lt[2*i] = val;
            lt[2*i + 1] = val;
        }
        return;
    }

    int mid = (L+R)/2;
    rangeUpdate(2*i, L, mid, qs, qe, val);
    rangeUpdate(2*i + 1, mid+1, R, qs, qe, val);

    st[i] = st[2*i] + st[2*i + 1];

}

void buildTree(int i, int L, int R)
{
    if(L == R){
        st[i] = arr[L];
        return;
    }

    int mid = (L+R)/2;
    buildTree(2*i, L, mid);
    buildTree(2*i + 1, mid+1, R);

    st[i] = st[2*i] + st[2*i + 1];
}

int main()
{
    int n, i, j, x, y, val, ans;
    cin>> n;

    for(i = 1; i <= n; i++)
        cin>> arr[i];

    buildTree(1, 1, n);

    cin>> val >> x >> y;

    rangeUpdate(1, 1, n, x, y, val);

    cin>> x >> y;

    ans = query(1, 1, n, x, y);

    for(j = 1; j <= 20; j++)
        cout<< st[j] << " ";
    cout<< "\n";

    for(j = 1; j <= 20; j++)
        cout<< lt[j] << " ";
    cout<< "\n";

    cout<< ans << "\n";

    return 0;
}
/*
8
3 1 5 0 8 3 0 0
2 4 8
5 6
*/
