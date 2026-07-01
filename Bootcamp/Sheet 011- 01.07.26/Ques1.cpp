#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    vector<long long> pref(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
        {
            pref[0] = arr[i];
        }
        else
        {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    unordered_map<long long, int> mpp;
    mpp[0] = 1;
    int maxLen = 0;
    long long curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        if (mpp.find(curr) == mpp.end())
        {
            mpp[curr] = i;
        }
        if (mpp.find(curr - k) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[curr - k]);
        }
    }
    cout << maxLen << endl;
    return 0;
}