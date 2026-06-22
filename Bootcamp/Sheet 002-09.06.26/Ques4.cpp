#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    long long n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> pref(n);
    pref[0] = arr[0];
    for (long long i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l > 0)
        {
            cout << pref[r] - pref[l - 1] << endl;
        }
        else
        {
            cout << pref[r] << endl;
        }
    }
    return 0;
}