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
    if(dp[idx][prev]!=-1)
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
    return dp[idx][prev]=ans;
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
    cout << helper(0, arr, dp, 3, n) << endl;
}