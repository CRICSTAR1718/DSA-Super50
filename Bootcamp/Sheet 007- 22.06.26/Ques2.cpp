#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{

    vis[node] = true;
    for (int &n : adj[node])
    {
        if (!vis[n])
        {
            dfs(n, adj, vis);
        }
    }
}
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adj, vis);
        }
    }
    cout << count << endl;
    return 0;
}