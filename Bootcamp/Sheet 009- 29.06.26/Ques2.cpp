#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int target, vector<vector<int>> &adj, bool &flag, vector<bool> &vis)
{
    vis[node] = true;
    if (node == target)
    {
        flag = true;
        return;
    }
    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, target, adj, flag, vis);
        }
    }
}
int main()
{
    // your code goes here
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = false;
    vector<bool> vis(n + 1, false);
    dfs(x, y, adj, flag, vis);
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}