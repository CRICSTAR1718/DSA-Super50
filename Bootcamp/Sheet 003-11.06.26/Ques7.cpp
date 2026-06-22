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
    map<int, int> mpp;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    long long ans = 0;
    for (int right = left; right < n; right++)
    {
        mpp[arr[right]]++;
        while (mpp[arr[right]] > 1)
        {
            mpp[arr[left]]--;
            left++;
        }
        ans += (right - left + 1);
    }
    cout << ans << "\n";
    return 0;
}