#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define MOD 1000000007
    int steppingStone(int n)
    {
        vector<int> dp(n + 1, -1);
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                dp[0] = 1;
            }
            else if (i == 1)
            {
                dp[1] = 1;
            }
            else
            {
                int left = dp[i - 1] % MOD;
                int right = dp[i - 2] % MOD;
                dp[i] = (left + right) % MOD;
            }
        }
        return dp[n] % MOD;
    }
};

int main()
{
    // Fast I/O
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