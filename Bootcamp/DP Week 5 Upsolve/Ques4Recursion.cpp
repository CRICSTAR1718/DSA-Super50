#include <bits/stdc++.h>
using namespace std;
long long helper(long long idx, long long val, vector<long long> &R, vector<long long> &C, long long N, long long F)
{
    if (idx == N - 1)
    {
        return 0;
    }
    long long ans = LLONG_MAX / 2;
    for (int j = idx + 1; j < N; j++)
    {
        if (R[j] > val)
        {
            continue;
        }
        long long dist = j - idx;
        long long cost = dist * dist + C[j];
        long long next = helper(j, val, R, C, N, F);
        if (next == LLONG_MAX / 2)
            continue;
        ans = min(ans, cost + next);
    }
    return ans;
}
bool feasible(long long X, vector<long long> &R, vector<long long> &C, long long N, long long F)
{
    if (R[0] > X || R[N - 1] > X)
    {
        return false;
    }
    long long cost = helper(0, X, R, C, N, F);
    return cost != LLONG_MAX / 2 && cost <= F;
}
int main()
{
    // your code goes here
    long long N, F;
    cin >> N >> F;
    vector<long long> R(N);
    vector<long long> C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> R[i];
    }
    for (int j = 0; j < N; j++)
    {
        cin >> C[j];
    }
    vector<long long> arr = R;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    long long ans = -1;
    long long low = 0;
    long long high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long x = arr[mid];
        if (feasible(x, R, C, N, F))
        {
            ans = x;
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