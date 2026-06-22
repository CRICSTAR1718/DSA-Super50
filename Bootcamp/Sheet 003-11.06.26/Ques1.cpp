#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, m, k;
        cin >> n >> k >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count = 0;
        int curr = 0;
        for (int i = 0; i < k; i++)
        {
            curr += arr[i];
        }
        if (curr == m)
        {
            count++;
        }
        for (int i = k; i < n; i++)
        {
            curr -= arr[i - k];
            curr += arr[i];
            if (curr == m)
            {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}