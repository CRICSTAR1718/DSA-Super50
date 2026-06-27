#include <bits/stdc++.h>
using namespace std;

bool possible(vector<long long> &arr, long long mid)
{
    int n = arr.size();
    int count = 0;
    int i = 0;

    while (i < n)
    {
        count++;
        long long start = arr[i];

        while (i < n && arr[i] - start <= 2 * mid)
        {
            i++;
        }
    }

    return count <= 3;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> arr(n);

        for (auto &x : arr)
            cin >> x;

        sort(arr.begin(), arr.end());

        long long low = 0;
        long long high = 1e9;
        long long ans = high;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (possible(arr, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }
}