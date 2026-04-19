#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long ans = 0;
        long long len = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= q)
            {
                len++;
            }
            else
            {
                if (len >= k)
                {
                    long long x = len - k + 1;
                    ans += (x * (x + 1)) / 2;
                }
                len = 0;
            }
        }
        // last segment
        if (len >= k)
        {
            long long x = len - k + 1;
            ans += (x * (x + 1)) / 2;
        }
        cout << ans << "\n";
    }
}