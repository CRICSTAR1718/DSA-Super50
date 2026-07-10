#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<long long> S(n);
    vector<long long> C(n);
    vector<long long> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        cin >> C[j];
    }
    dp[0] = S[0];
    for (int idx = 1; idx < n; idx++)
    {
        long long single = S[idx] + dp[idx - 1];
        long long combo = C[idx - 1];
        if (idx >= 2)
        {
            combo = C[idx - 1] + dp[idx - 2];
        }
        dp[idx] = min(single, combo);
    }
    cout << dp[n - 1] << endl;
    return 0;
}