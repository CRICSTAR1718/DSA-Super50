#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &arr, int idx, vector<int> &dp, int k)
{
    if (idx == 0)
    {
        return dp[0] = 0;
    }
    if (idx == 1)
    {
        return dp[1] = abs(arr[1] - arr[0]);
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int ans = INT_MAX;
    for (int i = idx-1; i >= max(0,idx-k); i--)
    {
        ans = min(ans, (helper(arr, i, dp, k) + abs(arr[idx] - arr[i])));
    }
    return dp[idx] = ans;
}
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >>k;
    vector<int> arr(n);
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << helper(arr, n - 1, dp, k) << endl;
    return 0;
}