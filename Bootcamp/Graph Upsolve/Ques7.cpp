// TLE

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> sluggishness(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> sluggishness[i];
    }
    long long INF = LLONG_MAX;
    // time[node][best_bicycle]
    vector<vector<long long>> time(n + 1, vector<long long>(1001, INF));

    // pq[time][bicycle][node]

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    // {starting time=0; best_bicycle=cycle at node 1; starting_node=1}
    time[1][sluggishness[1]] = 0;
    pq.push({0, sluggishness[1], 1});
    while (!pq.empty())
    {
        tuple<long long, int, int> curr = pq.top();
        pq.pop();
        long long t = get<0>(curr);
        int b = get<1>(curr);
        int node = get<2>(curr);
        if (t != time[node][b])
        {
            continue;
        }
        for (auto &it : adj[node])
        {
            int nextNode = it.first;
            int w = it.second;
            int nb = min(b, sluggishness[nextNode]);
            long long nt = t + w * b * 1LL;
            if (nt < time[nextNode][nb])
            {
                time[nextNode][nb] = nt;
                pq.push({nt, nb, nextNode});
            }
        }
    }
    long long ans = LLONG_MAX;
    for (int i = 1; i <= 1000; i++)
    {
        ans = min(ans, time[n][i]);
        // ans=*min_element(time[n].begin(), time[n].end());
    }
    cout << ans << "\n";

    return 0;
}