#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main()
{
    // your code goes here
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if (nr < 0 || nc < 0 || nr >= r || nc >= c)
                    {
                        ans++;
                    }
                    else if (mat[nr][nc] == 0)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}