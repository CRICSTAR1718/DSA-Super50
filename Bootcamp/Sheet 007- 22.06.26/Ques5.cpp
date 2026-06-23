#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1);
    vis[1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
    return 0;
}