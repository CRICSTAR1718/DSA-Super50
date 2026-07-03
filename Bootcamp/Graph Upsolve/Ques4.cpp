#include <bits/stdc++.h>
using namespace std;
bool isSimilar(string &a, string &b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            count++;
        }
    }
    return count == 0 || count == 2;
}
void dfs(int node, vector<string> &strs, vector<bool> &vis, int n)
{
    vis[node] = true;
    for (int j = 0; j < n; j++)
    {
        if (!vis[j])
        {
            if (isSimilar(strs[node], strs[j]))
            {
                vis[j] = true;
                dfs(j, strs, vis, n);
            }
        }
    }
}

int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    vector<bool> vis(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, strs, vis, n);
        }
    }
    cout << count << endl;
    return 0;
}