#include <bits/stdc++.h>
using namespace std;

long long fun(int r1, int c1, int r2,vector<vector<long long>> &grid,vector<vector<vector<long long>>> &dp,vector<vector<vector<int>>> &vis)
{
    int n = grid.size();
    int c2 = r1 + c1 - r2;

    if(r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 ||
       r1 >= n || c1 >= n || r2 >= n || c2 >= n)
        return LLONG_MIN;

    if(r1 == n - 1 && c1 == n - 1)
        return grid[n - 1][n - 1];

    if(vis[r1][c1][r2])
        return dp[r1][c1][r2];

    vis[r1][c1][r2] = 1;

    long long money = grid[r1][c1];

    if(r1 != r2 || c1 != c2)
        money += grid[r2][c2];

    long long op1 = fun(r1 + 1, c1, r2 + 1, grid, dp, vis);
    long long op2 = fun(r1 + 1, c1, r2, grid, dp, vis);
    long long op3 = fun(r1, c1 + 1, r2 + 1, grid, dp, vis);
    long long op4 = fun(r1, c1 + 1, r2, grid, dp, vis);

    long long ans = max({op1, op2, op3, op4});

    if(ans == LLONG_MIN)
        return dp[r1][c1][r2] = LLONG_MIN;

    return dp[r1][c1][r2] = money + ans;
}
int main()
{
    int n;
    cin >> n;

    vector<vector<long long>> grid(n, vector<long long>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(n, 0)));
    vector<vector<vector<int>>> vis(n,vector<vector<int>>(n,vector<int>(n, 0)));
    cout << fun(0, 0, 0, grid, dp, vis);

    return 0;
}