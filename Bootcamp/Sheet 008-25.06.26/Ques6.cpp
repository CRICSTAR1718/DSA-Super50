#include <bits/stdc++.h>
using namespace std;
bool check(int mid, vector<int> &arr, int n, int k)
{
    long long curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i] / mid;
    }
    return curr >= k;
}
int main()
{
    // your code goes here
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int low = 1;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        high = max(high, arr[i]);
    }
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid, arr, n, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}