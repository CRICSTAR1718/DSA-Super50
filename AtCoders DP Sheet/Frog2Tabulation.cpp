#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int idx = 0; idx < n; idx++)
    {
        if (idx == 0)
        {
            dp[0] = 0;
        }
        else{
            int ans = INT_MAX;
            for (int i = idx - 1; i >= max(0, idx - k); i--)
            {
                ans = min(ans, (dp[i] + abs(arr[idx] - arr[i])));
            }
            dp[idx] = ans;
        }
        
    }
        cout << dp[n-1] << endl;
    return 0;
}