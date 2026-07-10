#include <bits/stdc++.h>
using namespace std;
long long helper(int idx, vector<long long>&S, vector<long long>&C, vector<long long>&dp)
{
    if(idx<0)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    if(idx==0)
    {
        return dp[idx]=S[0];
    }
    long long single=S[idx]+helper(idx-1, S, C, dp);
    long long combo=LLONG_MAX;
    if(idx>=1)
    {
        combo=C[idx-1]+helper(idx-2, S, C, dp);
    }
    return dp[idx]=min(single, combo);
}
int main() {
    // your code goes here
    int n;
    cin>>n;
    vector<long long>S(n);
    vector<long long>C(n);
    vector<long long>dp(n, -1);
    for(int i=0; i<n; i++)
    {
        cin>>S[i];
    }
    for(int j=0; j<n-1; j++)
    {
        cin>>C[j];
    }
    cout<<helper(n-1, S, C, dp)<<endl;
    return 0;
}