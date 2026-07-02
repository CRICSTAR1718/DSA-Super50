#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3, 0));
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        dist[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) // intermediate node
    {
        for (int i = 0; i < n; i++) // Source node
        {
            for (int j = 0; j < n; j++) // Destination
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}