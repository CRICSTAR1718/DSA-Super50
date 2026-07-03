




// WRONG
#include <bits/stdc++.h>
using namespace std;
void helper(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, int d, int t, int &c)
{
    vis[node] = true;
    if (d <= t)
    {
        c++;
    }
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            vis[it.first] = true;
            helper(it.first, adj, vis, d + it.second, t, c);
        }
    }
}
int main()
{
    // your code goes here
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int ans = -1;
    int count = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        vector<bool> vis(n, false);
        helper(i, adj, vis, 0, t, c);
        if (c > 0 && c <= count)
        {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}