#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        // Write your code here
        vector<int> indegree(n);
        int ans = 0;
        vector<vector<bool>> mat(n, vector<bool>(n, false));
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            mat[u][v] = true;
            mat[v][u] = true;
            indegree[u]++;
            indegree[v]++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, indegree[i] + indegree[j] - mat[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<vector<int>> roads(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> roads[i][0] >> roads[i][1];
    }

    Solution obj;
    cout << obj.maximalNetworkRank(n, roads) << "\n";

    return 0;
}