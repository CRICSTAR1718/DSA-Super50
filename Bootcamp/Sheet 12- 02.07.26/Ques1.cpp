#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    long long v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e, vector<int>(3));
    long long val = 100000000;
    for (int i = 0; i < e; i++)
    {
        int u, d, w;
        cin >> u >> d >> w;
        edges[i][0] = u;
        edges[i][1] = d;
        edges[i][2] = w;
    }
    int src;
    cin >> src;
    vector<long long> res(v, val);
    res[src] = 0;
    for (int i = 1; i < v; i++)
    {
        for (auto &edge : edges)
        {
            int u, d, w;
            u = edge[0];
            d = edge[1];
            w = edge[2];
            if (res[u] != val && res[d] > res[u] + w)
            {
                res[d] = res[u] + w;
            }
        }
    }
    bool flag = true;
    for (auto &i : edges)
    {
        int u, d, w;
        u = i[0];
        d = i[1];
        w = i[2];
        if (res[u] != val && res[d] > res[u] + w)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < v; i++)
        {
            cout << res[i] << " ";
        }
    }
    return 0;
}