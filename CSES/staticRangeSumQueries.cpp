#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, q;
    // Input length of array and number of queries
    cin >> n >> q;
    // Input array
    vector<long long> arr(n);
    vector<long long> prefSum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Prefix Sum
    prefSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefSum[i] = prefSum[i - 1] + arr[i];
    }
    while (q--)
    {
        long long l, r;
        // Input left and right indices of query
        cin >> l >> r;
        // Converting to 0-based indexing
        l--;
        r--;
        long long result= prefSum[r] - ((l > 0) ? prefSum[l - 1] : 0);
        cout << result << endl;
    }
}