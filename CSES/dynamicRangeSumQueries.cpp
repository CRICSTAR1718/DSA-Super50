#include <bits/stdc++.h>
using namespace std;

void update(int idx, vector<long long> &fenwick, long long val)
{
    while (idx < fenwick.size())
    {
        fenwick[idx] += val;
        idx += (idx & -idx);
    }
}

void buildFenwick(int n, vector<long long> &arr, vector<long long> &fenwick)
{
    for (int i = 1; i <= n; i++)
    {
        update(i, fenwick, arr[i]);
    }
}

long long pref(int idx, vector<long long> &fenwick)
{
    long long ans = 0;
    while (idx > 0)
    {
        ans += fenwick[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> fenwick(n + 1, 0);
    buildFenwick(n, arr, fenwick);
    while (q--)
    {
        int val;
        int f;
        long long s;
        cin >> val >> f >> s;
        if (val == 1)
        {
            long long diff = s - arr[f];
            arr[f] = s;
            update(f, fenwick, diff);
        }
        else
        {
            cout << pref(s, fenwick) - pref(f - 1, fenwick) << endl;
        }
    }
}