#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n;
    long long K;
    cin >> n >> K;
    vector<long long> calories(n);
    vector<long long> protein(n);
    vector<long long> dp(K + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> calories[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> protein[j];
    }
    for (int i = 0; i <= K; i++)
    {
        if (i >= calories[0])
        {
            dp[i] = protein[0];
        }
        else
        {
            dp[i] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = K; j >= 0; j--)
        {
            long long notPick = dp[j];
            long long pick = 0;
            if (calories[i] <= j)
            {
                pick = protein[i] + dp[j - calories[i]];
            }
            dp[j] = max(pick, notPick);
        }
    }
    cout << dp[K];
    return 0;
}