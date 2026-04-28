// Memoization
#include <bits/stdc++.h>
using namespace std;
const int MOD = 676767677;
int n;
vector<int> a;
vector<long long> dp;
long long solve(int pos)
{
    if (pos == n)
        return 0;
    if (dp[pos] != -1)
        return dp[pos];
    long long ans = LLONG_MAX;
    long long prod;
    int last;
    for (int i = pos; i < n; i++)
    {
        if (i == pos)
        {
            prod = a[i];
            last = a[i];
        }
        else
        {
            if (a[i] < last)
                break;
            prod = (prod * a[i]) % MOD;
            last = a[i];
        }
        ans = min(ans, (prod + solve(i + 1)) % MOD);
    }
    return dp[pos] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        dp.assign(n, -1);
        cout << solve(0) % MOD << "\n";
    }
}

// Recursion
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<int> a;
// long long solve(int pos)
// {
//     if (pos == n)
//         return 0;
//     long long ans = LLONG_MAX;
//     long long prod;
//     int last;
//     for (int i = pos; i < n; i++)
//     {
//         if (i == pos)
//         {
//             prod = a[i];
//             last = a[i];
//         }
//         else
//         {
//             if (a[i] < last)
//                 break;
//             prod = prod * a[i];
//             last = a[i];
//         }
//         ans = min(ans, prod + solve(i + 1));
//     }
//     return ans;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         a.resize(n);
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         cout << solve(0) << "\n";
//     }
// }