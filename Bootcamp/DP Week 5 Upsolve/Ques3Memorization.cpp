#include <bits/stdc++.h>
using namespace std;
long long helper(int i, int j, vector<vector<int>> &mat, vector<vector<long long>> &dp)
{
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == 0 && j == 0)
    {
        return dp[i][j] = 0;
    }

    long long up = LLONG_MAX;
    if (i > 0)
    {
        up = abs(mat[i][j] - mat[i - 1][j]) + helper(i - 1, j, mat, dp);
    }
    long long left = LLONG_MAX;
    if (j > 0)
    {
        left = abs(mat[i][j] - mat[i][j - 1]) + helper(i, j - 1, mat, dp);
    }
    return dp[i][j] = min(up, left);
}
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<long long>> dp(n, vector<long long>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << helper(n - 1, m - 1, mat, dp);
    return 0;
}