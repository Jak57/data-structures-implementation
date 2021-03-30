#include<bits/stdc++.h>

using namespace std;

int main()
{
    char arr[1000] = {'a', 'b', 'c', 'd'};
    int n, i, j, t, total, mask;
    cin>> t;

    for(i = 1; i <= t; i++)
    {
        cin>> n;
        total = 1 << n;
        for(mask = 0; mask < total; mask++)
        {
            for(j = 0; j < n; j++)
            {
                if((mask & (1<<j)) != 0)
                    cout<< arr[j] << " ";
            }
            cout<< "\n";
        }
    }


    return 0;
}

/*
3
2
3
4
*/
