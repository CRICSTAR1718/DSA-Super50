#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<bool> visited(n + 1, false);
        bool possible = true;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                vector<int> indices;
                int x = i;
                while (x <= n)
                {
                    visited[x] = true;
                    indices.push_back(x);
                    x *= 2;
                }
                vector<int> current_vals;
                vector<int> target_vals;
                for (int idx : indices)
                {
                    current_vals.push_back(a[idx]);
                    target_vals.push_back(idx);
                }
                sort(current_vals.begin(), current_vals.end());
                sort(target_vals.begin(), target_vals.end());
                if (current_vals != target_vals)
                {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}