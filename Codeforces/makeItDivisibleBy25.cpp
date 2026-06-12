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
        string s;
        cin >> s;
        int n = s.size();
        int ans = 1e9;
        vector<string> target = {"00", "25", "50", "75"};
        for (string p : target)
        {
            char a = p[0], b = p[1];
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[j] != b)
                    continue;
                for (int i = j - 1; i >= 0; i--)
                {
                    if (s[i] == a)
                    {
                        ans = min(ans, (n - 1 - j) + (j - i - 1));
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}