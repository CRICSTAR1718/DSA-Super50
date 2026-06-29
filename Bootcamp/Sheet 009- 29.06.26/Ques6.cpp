#include <bits/stdc++.h>
using namespace std;
bool is_similar(string &i, string &j)
{
    int c = 0;
    for (int k = 0; k < i.size(); k++)
    {
        if (i[k] != j[k])
        {
            c++;
        }
    }
    return c == 2 || c == 0;
}
void dfs(int i, vector<string> &given, vector<bool> &vis, int n)
{
    vis[i] = true;
    for (int j = 0; j < n; j++)
    {
        if (!vis[j])
        {
            if (is_similar(given[i], given[j]))
            {
                vis[j] = true;
                dfs(j, given, vis, n);
            }
        }
    }
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<string> given(n);
    for (int i = 0; i < n; i++)
    {
        cin >> given[i];
    }
    vector<bool> vis(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, given, vis, n);
        }
    }
    cout << count << endl;
    return 0;
}