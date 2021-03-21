#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[10000], n, i, j, c1, c0, p, ans = 0;;
    cin>> n;

    for(i = 1; i <= n; i++)
        cin>> arr[i];

    for(i = 0; i < 32; i++){
        c1 = 0; c0 = 0;

        for(j = 1; j <= n; j++){
            if((arr[j] & (1 << i)) > 0)
                c1++;
            else
                c0++;
        }
        p = c1 * c0;

        ans += (p * (1 << i));
    }

    cout<< ans << "\n";

    return 0;
}
/*
3
5 3 9
*/
