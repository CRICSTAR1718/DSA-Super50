#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> mat(n + 1, vector<int>(n+1));
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            mat[i][j] = (c == '*');
        }
    }
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pref[i][j] = mat[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    while(q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];
        cout << ans << "\n";
    }
}