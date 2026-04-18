#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    queue<int> q;
    q.push(1);
    vector<bool> vis(n+1, false);
    vis[1] = true;
    int count = 1;
    while(!q.empty())
    {
        int node= q.front();
        q.pop();
        for(int i: adj[node])
        {
            if(!vis[i])
            {
                vis[i] = true;
                count++;
                q.push(i);
            }
        }
    }
    cout << count << endl;
}