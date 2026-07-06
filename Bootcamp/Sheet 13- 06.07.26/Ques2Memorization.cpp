#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define MOD 1000000007
    int helper(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return dp[0] = 1;
        }
        if (n == 1)
        {
            return dp[1] = 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int left = helper(n - 1, dp) % MOD;
        int right = helper(n - 2, dp) % MOD;
        return dp[n] = (left + right) % MOD;
    }
    int steppingStone(int n)
    {

        vector<int> dp(n + 1, -1);
        return helper(n, dp) % MOD;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n)
    {
        Solution sol;
        cout << sol.steppingStone(n) << "\n";
    }

    return 0;
}