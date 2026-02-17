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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        // Find maximum frequency
        int mx = 1, currFreq = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                currFreq++;
            }
            else
            {
                mx = max(mx, currFreq);
                currFreq = 1;
            }
        }
        mx = max(mx, currFreq);
        int operations = 0;
        int curr = mx;
        while (curr < n)
        {
            operations++; // clone
            int add = min(curr, n - curr);
            operations += add; // swaps
            curr += add;
        }
        cout << operations << "\n";
    }

    return 0;
}
