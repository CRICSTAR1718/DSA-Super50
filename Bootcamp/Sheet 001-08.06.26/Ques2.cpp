#include <bits/stdc++.h>
using namespace std;

long long find(long long n, unordered_map<long long, long long> &dp)
{
    if (dp.count(n))
    {
        return dp[n];
    }
    return dp[n] = find(n / 2, dp) + find(n / 3, dp);
}
int main()
{
    // your code goes here
    long long n;
    cin >> n;
    unordered_map<long long, long long> dp;
    dp[0] = 1;
    long long val = find(n, dp);
    cout << val << endl;
    return 0;
}