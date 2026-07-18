#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> dp;

int fun(int idx, int prev)
{
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][prev] != -1)
    {
        return dp[idx][prev];
    }

    int ans = 1 + fun(idx + 1, 0);

    if ((a[idx] == 1 || a[idx] == 3) && prev != 1)
    {
        ans = min(ans, fun(idx + 1, 1));
    }

    if ((a[idx] == 2 || a[idx] == 3) && prev != 2)
    {
        ans = min(ans, fun(idx + 1, 2));
    }

    return dp[idx][prev] = ans;
}

int main()
{
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp.assign(n, vector<int>(3, -1));

    cout << fun(0, 0);

    return 0;
}