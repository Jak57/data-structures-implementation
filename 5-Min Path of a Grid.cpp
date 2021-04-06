1.

// Minimum distance from (1, 1) to (row, col) of a 2D grid using DP

#include <bits/stdc++.h>
#define INF 100000000

using namespace std;

int main()
{
    int row, col, i, j, a, b;
    int arr[100][100];
    cin>> row >> col;

    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
            cin>> arr[i][j];
    }

    for (i = 1; i <= col + 1; i++)
        arr[row + 1][i] = INF;

    for (j = 1; j <= row + 1; j++)
        arr[j][col + 1] = INF;

    arr[row+1][col] = 0;
    arr[row][col+1] = 0;

    for (i = row; i >= 1; i--)
    {
        for (j = col; j >= 1; j--)
        {
            a = arr[i][j+1];
            b = arr[i+1][j];
            arr[i][j] = arr[i][j] + min(a, b);

        }
    }

    // Storing distances from (i, j) to (row, col)
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
            cout<< arr[i][j] << " ";
        cout<< "\n";
    }

    // Min distance from (1, 1) to (row, col)
    cout<< arr[1][1] << "\n";

    return 0;
}
/*
3 4
5 1 2 6
9 9 7 5
3 1 4 8
*/

2.
    
// Minimum distance from first row to last row of a 2D grid using DP

#include <bits/stdc++.h>
#define INF 100000000

using namespace std;

int main()
{
    int row, col, i, j, a, b, c, d;
    int arr[100][100];
    cin>> row >> col;

    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
            cin>> arr[i][j];
    }

    for (i = 0; i <= col + 1; i++)
    {
        arr[row + 1][i] = INF;

    }

    for (j = 1; j <= row + 1; j++)
    {
        arr[j][col + 1] = INF;
        arr[j][0] = INF;
    }

    for (i = row-1; i >= 1; i--)
    {
        for (j = col; j >= 1; j--)
        {
            a = arr[i+1][j-1];
            b = arr[i+1][j];
            c = arr[i+1][j+1];
            d = min(a, b);

            arr[i][j] = arr[i][j] + min(c, d);

        }
    }

    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
            cout<< arr[i][j] << " ";
        cout<< "\n";
    }

    int ans = 100000000;
    for (j = 1; j <= col; j++)
        ans = min(ans, arr[1][j]);

    cout<< ans << "\n";

    return 0;
}
/*
3 4
5 1 2 6
9 9 7 5
3 1 4 8
*/

