#include <bits/stdc++.h>
using namespace std;
long long countPairs(vector<long long> &arr, long long mid, int n)
{
    long long count = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        while (arr[right] - arr[left] > mid)
        {
            left++;
        }
        count += right - left;
    }
    return count;
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long pairs = 1LL * n * (n - 1) / 2;
    long long idx = (pairs - 1) / 2;
    long long low = 0;
    long long high = arr[n - 1] - arr[0];
    long long ans = high;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long count = countPairs(arr, mid, n);
        if (count > idx)
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