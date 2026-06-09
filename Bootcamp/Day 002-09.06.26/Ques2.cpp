#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    vector<int> arr(n);
    vector<long long> pref(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
        {
            if (arr[i] == 2)
            {
                pref[i] = pref[i - 1] + 1;
            }
            else
            {
                pref[i] = pref[i - 1];
            }
        }
        else
        {
            if (arr[i] == 2)
            {
                pref[i] = 1;
            }
            else
            {
                pref[i] = 0;
            }
        }
    }
    long long q;
    cin >> q;
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        long long ans = 0;
        long long noOfTwos = 0;
        if (l > 0)
        {
            noOfTwos = pref[r] - pref[l - 1];
        }
        else
        {
            noOfTwos = pref[r];
        }
        int odds = (r - l + 1) - noOfTwos;
        ans = noOfTwos * odds;
        cout << ans << "\n";
    }
    return 0;
}