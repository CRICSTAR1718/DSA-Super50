#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> &mat)
{
    if (i == 0 && j == 0)
    {
        return 0;
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    int up = INT_MAX;
    if (i > 0)
    {
        up = abs(mat[i][j] - mat[i - 1][j]) + helper(i - 1, j, mat);
    }
    int left = INT_MAX;
    if (j > 0)
    {
        left = abs(mat[i][j] - mat[i][j - 1]) + helper(i, j - 1, mat);
    }
    return min(up, left);
}
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << helper(n - 1, m - 1, mat);
    return 0;
}