#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
ll fact[MAXN];
int main()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll X = a[0];
        for (int i = 1; i < n; i++)
        {
            X &= a[i];
        }
        int cnt = 0;
        for (auto x : a)
        {
            if (x == X)
                cnt++;
        }
        if (cnt < 2)
        {
            cout << 0 << "\n";
            continue;
        }
        ll ans = (ll)cnt * (cnt - 1) % MOD;
        ans = ans * fact[n - 2] % MOD;
        cout << ans << "\n";
    }
    return 0;
}