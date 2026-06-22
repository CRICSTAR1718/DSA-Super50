#include <bits/stdc++.h>
using namespace std;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
void dfs(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int nr = i + di[k];
        int nc = j + dj[k];
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && mat[nr][nc] == 1)
        {
            dfs(nr, nc, n, m, mat, vis);
        }
    }
}
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == 1)
            {
                count++;
                dfs(i, j, n, m, mat, vis);
            }
        }
    }
    cout << count << endl;
    return 0;
}