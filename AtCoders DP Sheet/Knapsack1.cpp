#include <bits/stdc++.h>
using namespace std;

long long knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<long long>> dp(n, vector<long long>(W + 1, 0));
    // Base case
    for (int w = wt[0]; w <= W; w++)
    {
        dp[0][w] = val[0];
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int w = 0; w <= W; w++)
        {
            long long notTake = dp[idx - 1][w];
            long long take = 0;
            if (wt[idx] <= w)
            {
                take = val[idx] + dp[idx - 1][w - wt[idx]];
            }
            dp[idx][w] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    vector<int> wt(n), val(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(W, val, wt) << "\n";
    return 0;
}