#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
            if (mat[i][j] == 0)
            {
                vis[i][j] = true;
            }
        }
    }
    int minTime = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int r = node.first.first;
        int c = node.first.second;
        int t = node.second;
        minTime = max(t, minTime);
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n)
            {
                if (!vis[nr][nc])
                {
                    vis[nr][nc] = true;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                minTime = -1;
            }
        }
    }
    cout << minTime << endl;

    return 0;
}