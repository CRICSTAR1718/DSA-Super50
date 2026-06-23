// BFS

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


// DFS
// #include <bits/stdc++.h>
// using namespace std;
// bool dfs(int node, vector<vector<int>> &adj, vector<int> &color)
// {
//     for (int &it : adj[node])
//     {
//         if (color[it] == -1)
//         {
//             color[it] = !color[node];
//             if (!dfs(it, adj, color))
//             {
//                 return false;
//             }
//         }
//         else if (color[it] == color[node])
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     // your code goes here
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int v, u;
//         cin >> v >> u;
//         adj[v].push_back(u);
//         adj[u].push_back(v);
//     }
//     bool flag = true;
//     vector<int> color(n + 1, -1);
//     for (int i = 1; i <= n; i++)
//     {
//         if (color[i] == -1)
//         {
//             color[i] = 0;
//             if (!dfs(i, adj, color))
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     if (flag)
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }
//     return 0;
// }