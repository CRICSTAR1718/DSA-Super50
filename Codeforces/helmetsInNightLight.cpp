#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, p;
        cin >> n >> p;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<long long> b(n);
        vector<pair<long long, long long>> mpp;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mpp.push_back({b[i], a[i]});
        }
        sort(mpp.begin(), mpp.end());
        long long ans = p;
        long long rem = n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            if(mpp[i].first<p)
            {
                long long peopleInformed = min(mpp[i].second, rem);
                ans += peopleInformed * mpp[i].first;
                rem -= peopleInformed;
            }
            if(rem==0 || mpp[i].first>=p)
            {
                break;
            }
        }
        if(rem)
        {
            ans += rem * p;
        }
        cout << ans << endl;
    }

}