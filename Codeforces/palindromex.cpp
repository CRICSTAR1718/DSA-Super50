#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++)
            cin >> a[i];

        vector<vector<int>> pos(n);
        for (int i = 0; i < 2 * n; i++)
        {
            pos[a[i]].push_back(i);
        }

        int L = 2 * n, R = -1;
        int ans = 0;

        for (int k = 0; k < n; k++)
        {
            L = min(L, pos[k][0]);
            R = max(R, pos[k][1]);

            if (R - L + 1 == 2 * (k + 1))
            {
                ans = k + 1;
            }
            else
            {
                break; 
            }
        }

        cout << ans << "\n";
    }
}