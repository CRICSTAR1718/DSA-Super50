#include <bits/stdc++.h>
using namespace std;
bool check(int i, int j, int &m, int &n, vector<string> &grid, vector<pair<int, int>> &shape)
{
    for (auto &it : shape)
    {
        int ni = i + it.first;
        int nj = j + it.second;
        if (ni < 0 || nj < 0 || ni >= n || nj >= m)
        {
            return false;
        }
        if (grid[ni][nj] != '.')
        {
            return false;
        }
    }
    return true;
}
void place(int i, int j, int &m, int &n, vector<string> &grid, vector<pair<int, int>> &shape, char ch)
{
    for (auto &it : shape)
    {
        int ni = i + it.first;
        int nj = j + it.second;
        grid[ni][nj] = ch;
    }
}
bool solve(int &n, int &m, vector<string> &grid, vector<vector<pair<int, int>>> &shapes)
{
    int r = -1;
    int c = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                r = i;
                c = j;
                break;
            }
        }
        if (r != -1)
        {
            break;
        }
    }
    if (r == -1)
    {
        return true;
    }
    for (auto &s : shapes)
    {
        if (check(r, c, m, n, grid, s))
        {
            place(r, c, m, n, grid, s, 'P');
            if (solve(n, m, grid, shapes))
            {
                return true;
            }
            place(r, c, m, n, grid, s, '.');
        }
    }
    return false;
}
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    int emptyCellCount = 0;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (char &ch : grid[i])
        {
            if (ch == '.')
            {
                emptyCellCount++;
            }
        }
    }
    if (emptyCellCount % 3)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        vector<vector<pair<int, int>>> shapes =
            {
                {{0, 0}, {0, 1}, {1, 0}},
                {{0, 0}, {0, 1}, {1, 1}},
                {{0, 0}, {1, 0}, {1, 1}},
                {{0, 1}, {1, 0}, {1, 1}}};

        if (solve(n, m, grid, shapes))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}