#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> count(n, 0);
    if (s[0] == 'a')
    {
        count[0]++;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'a')
        {
            count[i] = count[i - 1] + 1;
        }
        else
        {
            count[i] = count[i - 1];
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l > 0)
        {
            cout << count[r] - count[l - 1] << "\n";
        }
        else
        {
            cout << count[r] << "\n";
        }
    }
    return 0;
}