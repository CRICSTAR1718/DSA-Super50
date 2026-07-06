#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define MOD 1000000007
    int helper(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 1;
        }

        int left = helper(n - 1) % MOD;
        int right = helper(n - 2) % MOD;
        return (left + right) % MOD;
    }
    int steppingStone(int n)
    {
        return helper(n) % MOD;
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