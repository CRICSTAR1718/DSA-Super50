#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int k = n;
        long long mini = LLONG_MAX;
        vector<long long> mini2;
        while(k--)
        {
            int m;
            cin >> m;
            long long mn1 = LLONG_MAX, mn2 = LLONG_MAX;
            for (int i = 0; i < m; i++)
            {
                long long x;
                cin >> x;
                if (x < mn1)
                {
                    mn2 = mn1;
                    mn1 = x;
                }
                else if (x < mn2)
                {
                    mn2 = x;
                }
            }
            mini = min(mini, mn1);
            mini2.push_back(mn2);
        }
        long long ans = mini;
        sort(mini2.begin(), mini2.end());
        for (int i = 1; i < n; i++)
        {
            ans += mini2[i];
        }
        cout << ans << endl;
    }
}