#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<int> chocolates(n);
    for (int i = 0; i < n; i++)
    {
        cin >> chocolates[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        queue<int> q;
        q.push(i);
        vis[i] = true;
        int mini = chocolates[i];
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            mini = min(mini, chocolates[node]);
            for (auto &it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        ans += mini;
    }
    cout << ans << endl;
    return 0;
}