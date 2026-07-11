#include <bits/stdc++.h>
using namespace std;
long long helper(int idx, long long K, vector<long long> &calories, vector<long long> &protein, vector<vector<long long>> &dp)
{
    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx][K] != -1)
    {
        return dp[idx][K];
    }
    if (idx == 0)
    {
        if (K >= calories[idx])
        {
            return dp[idx][K] = protein[0];
        }
        return dp[idx][K] = 0;
    }
    long long notPick = helper(idx - 1, K, calories, protein, dp);
    long long pick = 0;
    if (calories[idx] <= K)
    {
        pick = protein[idx] + helper(idx - 1, K - calories[idx], calories, protein, dp);
    }
    return dp[idx][K] = max(pick, notPick);
}
int main()
{
    // your code goes here
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> calories(n);
    vector<long long> protein(n);
    vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> calories[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> protein[j];
    }
    cout << helper(n - 1, k, calories, protein, dp);
    return 0;
}