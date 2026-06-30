#include <bits/stdc++.h>
using namespace std;
long long dijkstra(vector<vector<pair<long long, long long>>> &adj, long long n, long long src)
{
    vector<long long> dist(n + 1, 1e18);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        long long d = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        if (d > dist[node])
        {
            continue;
        }
        for (auto &it : adj[node])
        {
            long long adjNode = it.first;
            long long edgeW = it.second;
            if (d + edgeW < dist[adjNode])
            {
                dist[adjNode] = d + edgeW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    long long total = 0 * 1LL;
    for (int i = 0; i <= n; i++)
    {
        if (dist[i] == 1e18)
        {
            continue;
        }
        total += dist[i];
    }
    return 2 * 1LL * total;
}
int main()
{
    // your code goes here
    long long n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<long long, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }
    cout << dijkstra(adj, n, x);
    return 0;
}