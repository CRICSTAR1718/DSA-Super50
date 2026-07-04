#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, int &count)
    {
        vis[node] = true;
        count++;
        for (int it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        // Write your logic here to find the maximum bombs detonated
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long w1 = bombs[i][2];
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                //(x1-x2)^2-(y1-y2)^2<=w^2
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long w2 = bombs[j][2];
                long long dx = (x1 - x2) * (x1 - x2);
                long long dy = (y1 - y2) * (y1 - y2);
                long long w = w1 * w1;
                if ((dx + dy) <= w)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(n);
            int count = 0;
            dfs(i, adj, vis, count);
            ans = max(ans, count);
        }
        return ans;
    }
};

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n)
    {
        vector<vector<int>> bombs(n, vector<int>(3));
        for (int i = 0; i < n; ++i)
        {
            cin >> bombs[i][0] >> bombs[i][1] >> bombs[i][2];
        }

        Solution sol;
        cout << sol.maximumDetonation(bombs) << "\n";
    }
    return 0;
}