#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void helper(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int nr = i + dx[k];
        int nc = j + dy[k];
        if (nr >= 0 && nc >= 0 && nr < n && nc < m)
        {
            if (!vis[nr][nc] && mat[nr][nc] == 1)
            {
                helper(nr, nc, n, m, mat, vis);
            }
        }
    }
}
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && !vis[i][j])
            {
                count++;
                helper(i, j, n, m, mat, vis);
            }
        }
    }
    cout << count << endl;
    return 0;
}