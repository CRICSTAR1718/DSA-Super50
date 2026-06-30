#include <bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<pair<int, int>>> &adj, int n, int src, bool &flag, long long &maxi)
{
    vector<long long> dist(n + 1, LLONG_MAX);
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
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == LLONG_MAX)
        {
            flag = false;
            break;
        }
        maxi = max(maxi, dist[i]);
    }
}
int main()
{
    // your code goes here
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    bool flag = true;
    long long maxi = LLONG_MIN;
    dijkstra(adj, n, k, flag, maxi);
    if (flag)
    {
        cout << maxi << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}