#include <bits/stdc++.h>
using namespace std;
void generate(int i, int n, int a, int b, int c, string curr, vector<string> &res)
{
    if (i == n)
    {
        res.push_back(curr);
        return;
    }
    char ch = curr.back();
    if (ch == 'R')
    {
        if (b > 0)
        {
            generate(i + 1, n, a, b - 1, c, curr + 'G', res);
        }
        if (c > 0)
        {
            generate(i + 1, n, a, b, c - 1, curr + 'B', res);
        }
    }
    else if (ch == 'G')
    {
        if (a > 0)
        {
            generate(i + 1, n, a - 1, b, c, curr + 'R', res);
        }
        if (c > 0)
        {
            generate(i + 1, n, a, b, c - 1, curr + 'B', res);
        }
    }
    else if (ch == 'B')
    {
        if (a > 0)
        {
            generate(i + 1, n, a - 1, b, c, curr + 'R', res);
        }
        if (b > 0)
        {
            generate(i + 1, n, a, b - 1, c, curr + 'G', res);
        }
    }
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<string> res;
        if (a > 0)
        {
            generate(1, a + b + c, a - 1, b, c, "R", res);
        }
        if (b > 0)
        {
            generate(1, a + b + c, a, b - 1, c, "G", res);
        }
        if (c > 0)
        {
            generate(1, a + b + c, a, b, c - 1, "B", res);
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
    }
    return 0;
}