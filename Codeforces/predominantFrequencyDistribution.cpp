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

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            pref1[i] = pref1[i - 1];
            pref2[i] = pref2[i - 1];

            if (a[i] == 1)
            {
                pref1[i]++;
                pref2[i]++;
            }
            else if (a[i] == 2)
            {
                pref1[i]--;
                pref2[i]++;
            }
            else
            {
                pref1[i]--;
                pref2[i]--;
            }
        }

        vector<int> suffixMax(n + 2, INT_MIN);
        suffixMax[n] = INT_MIN;
        for (int i = n - 1; i >= 1; i--)
        {
            suffixMax[i] = max(suffixMax[i + 1], pref2[i]);
        }

        bool found = false;

        for (int i = 1; i <= n - 2; i++)
        {
            if (pref1[i] >= 0 && suffixMax[i + 1] >= pref2[i])
            {
                found = true;
                break;
            }
        }

        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}