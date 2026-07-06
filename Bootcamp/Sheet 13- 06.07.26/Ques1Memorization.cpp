#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &arr, int idx, vector<int> &dp)
{
    if (idx <= 0)
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
    return dp[idx] = min((helper(arr, idx - 1, dp) + abs(arr[idx] - arr[idx - 1])), (helper(arr, idx - 2, dp) + abs(arr[idx] - arr[idx - 2])));
}
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << helper(arr, n - 1, dp) << endl;
    return 0;
}