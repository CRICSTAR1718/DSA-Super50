#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> pieces(m);
    for (int i = 0; i < m; i++)
    {
        cin >> pieces[i];
    }
    sort(pieces.begin(), pieces.end());
    int ans = INT_MAX;
    for (int i = 0; i <= m - n; i++)
    {
        int diff = pieces[i + n - 1] - pieces[i];
        ans = min(ans, diff);
    }
    cout << ans << endl;
}