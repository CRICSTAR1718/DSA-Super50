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
        string a, b;
        cin >> a >> b;

        int i = 0, ans = 0;

        while (i < n)
        {
            int costV = (a[i] != b[i]);

            if (i + 1 < n)
            {
                int costV2 = (a[i + 1] != b[i + 1]);
                int costH = (a[i] != a[i + 1]) + (b[i] != b[i + 1]);

                if (costH <= costV + costV2)
                {
                    ans += costH;
                    i += 2;
                    continue;
                }
            }

            ans += costV;
            i++;
        }

        cout << ans << "\n";
    }
}