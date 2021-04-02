1.
    
#include <bits/stdc++.h>

using namespace std;

int arr[100001];
vector<int> st[400001];

void buildTree(int i, int L, int R)
{
    if (L == R)
    {
        st[i].push_back(arr[L]);
        return;
    }

    int mid = (L + R) / 2;
    buildTree(2*i, L, mid);
    buildTree(2*i + 1, mid+1, R);

    int n, m, k = 0, j = 0, a, b;
    n = st[2*i].size();
    m = st[2*i + 1].size();

    while((j < n) && (k < m))
    {
        a = st[2*i][j];
        b = st[2*i+1][k];
        if (a <= b)
        {
            st[i].push_back(a);
            j++;
        }
        else
        {
            st[i].push_back(b);
            k++;
        }

    }

    while( j < n)
    {
        st[i].push_back(st[2*i][j]);
        j++;
    }

    while (k < m)
    {
        st[i].push_back(st[2*i+1][k]);
        k++;
    }
}

int main()
{
    int n, i;
    cin>> n;
    for(i = 1; i <= n; i++)
        cin>> arr[i];


    buildTree(1, 1, n);

    for(i = 0; i < st[1].size(); i++)
    {

        cout<< st[1][i] << " ";
    }
    cout<< "\n";

    return 0;
}
/*
7
43 2 90 3 8 2 2
*/

2.
    
#include <bits/stdc++.h>

using namespace std;

int arr[100001], tem[100001];

void buildTree(int L, int R)
{
    if (L == R)
    {
        return;
    }

    int mid = (L + R) / 2;
    buildTree(L, mid);
    buildTree(mid+1, R);

    int i = L, j = mid+1, a, b, k = 1, u;

    while(i <= mid && j <= R)
    {
        if(arr[i] <= arr[j])
        {
            tem[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            tem[k] = arr[j];
            j++;
            k++;
        }

    }

    while(i <= mid)
    {
        tem[k] = arr[i];
        i++; k++;
    }
    while(j <= R)
    {
        tem[k] = arr[j];
        j++; k++;
    }
    int id = L;
    for(u = 1; u < k; u++)
    {
        arr[id] = tem[u];
        id++;
    }

}

int main()
{
    int n, i;
    cin>> n;
    for(i = 1; i <= n; i++)
        cin>> arr[i];

    buildTree(1, n);

    for(i = 1; i <= n; i++)
        cout<< arr[i] << " ";

    cout<< "\n";

    return 0;
}
/*
7
4 2 9 3 8 7 20
*/

