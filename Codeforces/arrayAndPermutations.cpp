#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    // store positions of elements in p
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        pos[p[i]] = i;
    }

    int last = -1;

    for (int i = 0; i < n; i++)
    {
        if (pos[b[i]] < last)
        {
            cout << "NO\n";
            return;
        }
        last = pos[b[i]];
    }

    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}