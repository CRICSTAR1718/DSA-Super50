#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int target, vector<vector<int>> &adj, vector<bool> &vis)
{
    if (node == target)
    {
        return true;
    }
    vis[node] = true;
    for (int &n : adj[node])
    {
        if (!vis[n])
        {
            if (dfs(n, target, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    // your code goes here
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bool path = false;
    if (dfs(x, y, adj, vis))
    {
        path = true;
    }
    if (path)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}