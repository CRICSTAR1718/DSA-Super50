#include <bits/stdc++.h>
using namespace std;
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
    for (int idx = 0; idx < n; idx++)
    {
        if (idx <= 0)
        {
            dp[0] = 0;
        }
        else if (idx == 1)
        {
            dp[1] = abs(arr[1] - arr[0]);
        }
        else
        {
            dp[idx] = min((dp[idx - 1] + abs(arr[idx] - arr[idx - 1])), (dp[idx - 2] + abs(arr[idx] - arr[idx - 2])));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}