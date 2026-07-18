#include<bits/stdc++.h>
using namespace std;
long long helper(int i, unordered_map<long long, long long> &mpp, vector<long long> &dp){
    if(i==0)
    {
        return 0;
    }
    if(i==1)
    {
        return mpp[1];
    }
    if(dp[i-1]==-1)
    {
        dp[i-1]=helper(i - 1, mpp, dp);
    }
    if (dp[i - 2] == -1)
    {
        dp[i - 2] = helper(i - 2, mpp, dp);
    }
    return max(dp[i - 1], (mpp[i] * i + dp[i - 2]));
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    int maxi = 0;
    unordered_map<long long, long long> mpp;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
        mpp[arr[i]]++;
    }
    vector<long long> dp(maxi + 1, -1);
    cout << helper(maxi, mpp, dp);
}