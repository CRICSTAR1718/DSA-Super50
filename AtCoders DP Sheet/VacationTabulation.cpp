#include <bits/stdc++.h>
using namespace std;
int a = 0;
int b = 1;
int c = 2;
int helper(int idx, vector<vector<int>> &arr, vector<vector<int>> &dp, int prev, int n)
{
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx][prev] != -1)
    {
        return dp[idx][prev];
    }
    int ans = INT_MIN;
    for (int j = 0; j < 3; j++)
    {
        if (j != prev)
        {
            ans = max(ans, (arr[idx][j] + helper(idx + 1, arr, dp, j, n)));
        }
    }
    return dp[idx][prev] = ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3, 0));
    vector<vector<int>> dp(n, vector<int>(4, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = arr[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arr[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arr[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}