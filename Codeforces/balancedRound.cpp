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
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        int maxLen = 1, currLen = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] <= k)
            {
                currLen++;
            }
            else
            {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }
        cout << n - maxLen << '\n';
    }
}