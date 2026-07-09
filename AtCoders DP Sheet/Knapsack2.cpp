#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

long long helper(int idx, int value, vector<int> &vals, vector<int> &wt, vector<vector<long long>> &dp)
{
    if (value == 0)
        return 0;
    if (idx < 0)
        return INF; 

    if (dp[idx][value] != -1)
        return dp[idx][value];

    long long notPick = helper(idx - 1, value, vals, wt, dp);

    long long pick = INF;
    if (vals[idx] <= value)
    {
        long long sub = helper(idx - 1, value - vals[idx], vals, wt, dp);
        if (sub != INF)
            pick = wt[idx] + sub;
    }

    return dp[idx][value] = min(pick, notPick);
}

int knapsack(long long W, int N, vector<int> &vals, vector<int> &wt)
{
    int V = accumulate(vals.begin(), vals.end(), 0);
    vector<vector<long long>> dp(N, vector<long long>(V + 1, -1));

    for (int i = V; i >= 0; i--)
    {
        if (helper(N - 1, i, vals, wt, dp) <= W)
            return i;
    }
    return 0;
}

int main()
{
    int N;
    long long W;
    cin >> N >> W;

    vector<int> vals(N), wt(N);
    for (int i = 0; i < N; i++)
        cin >> wt[i] >> vals[i];

    cout << knapsack(W, N, vals, wt) << endl;
}