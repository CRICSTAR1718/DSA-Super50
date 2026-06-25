#include <bits/stdc++.h>
using namespace std;
bool check(long long mid, int n, int k, vector<long long> &arr)
{
    long long curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += mid / arr[i];
    }
    return curr >= k;
}
int main()
{
    // your code goes here
    int n, k;
    cin >> n >> k;
    long long low = 0;
    long long mn = LLONG_MAX;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    long long high = mn * k * 1LL;
    long long ans = high;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, k, arr))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}