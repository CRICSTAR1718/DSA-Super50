#include <bits/stdc++.h>
using namespace std;
int helper(int n, vector<int> &price, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, price[i] + helper(n - i, price, dp));
    }
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> price[i];
    vector<int> dp(n + 1, -1);
    cout << helper(n, price, dp);
    return 0;
}