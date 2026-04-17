#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            int rem = a % k;
            if (rem == 0){
                rem = k;
            }
            v.push_back({rem, i + 1});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b)
            {
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first; });
        for (auto &p : v)
        {
            cout << p.second << " ";
        }
        cout << '\n';
    }
}