#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    // vector<vector<long long>>dp(n, vector<long long>(m,0));
    vector<long long> dp(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0) && (j == 0))
            {
                continue;
            }
            long long up = LLONG_MAX;
            if (i > 0)
            {
                up = abs(mat[i][j] - mat[i - 1][j]) + dp[j];
            }
            long long left = LLONG_MAX;
            if (j > 0)
            {
                left = abs(mat[i][j] - mat[i][j - 1]) + dp[j - 1];
            }
            dp[j] = min(up, left);
        }
    }
    cout << dp[m - 1];
    return 0;
}