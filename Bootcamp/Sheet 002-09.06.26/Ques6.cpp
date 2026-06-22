#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    unordered_map<long long, long long> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        count += mpp[arr[i]];
        count += mpp[k - arr[i]];
        if (arr[i] == (k - arr[i]))
        {
            count -= mpp[arr[i]];
        }
        mpp[arr[i]]++;
    }
    cout << count << endl;
    return 0;
}