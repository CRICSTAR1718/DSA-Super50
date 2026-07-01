#include <bits/stdc++.h>
using namespace std;
long long dfs(int node, vector<vector<pair<int, int>>> &adj, int start, int parent)
{
    for (auto it : adj[node])
    {
        int next = it.first;
        int cost = it.second;

        if (next == parent)
        {
            continue;
        }
        if (next == start)
        {
            return cost;
        }
        return cost + dfs(next, adj, start, node);
    }
    return 0;
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, c});
        tot += c;
    }
    int n1 = adj[1][0].first;
    int cost1 = adj[1][0].second;

    // int n2=adj[1][1].first;
    // int cost2=adj[1][1].second;

    long long dfs1 = cost1 + dfs(n1, adj, 1, 1);
    // long long dfs2=tot-(cost2+dfs(n2, adj, 1));

    long long ans = min(dfs1, tot - dfs1);
    cout << ans << endl;

    return 0;
}