#include<bits/stdc++.h>

using namespace std;

int arr[10000], st[40000];

void update(int i, int L, int R, int qi)
{
    if(L == R){
        st[i] = arr[L];
        return;
    }

    int mid = (L+R)/2;

    if(qi <= mid)
        update(2*i, L, mid, qi);
    else
        update(2*i + 1, mid+1, R, qi);

    st[i] = min(st[2*i], st[2*i + 1]);
}

void buildTree(int i, int L, int R)
{
    int mid;

    if(L == R){
        st[i] = arr[L];
        return;
    }

    mid = (L + R) / 2;
    buildTree(2*i, L, mid);
    buildTree(2*i + 1, mid+1, R);

    st[i] = min(st[2*i], st[2*i + 1]);

}

int main()
{
    int n, i, q, j, qi, val;
    cin>> n;

    for(i = 1; i <= n; i++)
        cin>> arr[i];

    buildTree(1, 1, n);

    cin>> q;

    for(j = 1; j <= q; j++)
    {
        cin>> qi >> val;
        arr[qi] = val;

        update(1, 1, n, qi);

        for(int k = 1; k <= 20; k++)
            cout<< st[k] << " ";
    }


    return 0;
}

/*
6
1 5 2 -3 4 -1
1
2 -2
*/
