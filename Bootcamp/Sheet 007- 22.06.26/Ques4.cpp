#include<bits/stdc++.h>
using namespace std;
bool bfs(int i, int n, vector<vector<int>> &adj, vector<int>&color)
{
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto &it: adj[node])
        {
            if(color[it]==-1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bool flag = true;
    vector<int> color(n+1, -1);
    for (int i = 0; i < n; i++)
    {
        if(color[i]==-1)
        {
            if(!bfs(i, n, adj, color))
            {
                flag=false;
            }
        }
    }
    if(flag)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}