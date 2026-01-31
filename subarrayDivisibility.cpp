#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long ans=0;
    unordered_map<long long, int>mpp;
    long long curSum=0;
    mpp[0]=1;
    for(int i=0; i<n; i++)
    {
        curSum+=arr[i];
        int mod=((curSum%n)+n)%n;
        if(mpp.count(mod))
        {
            ans+=mpp[mod];
        }
        mpp[mod]++;
    }
    cout<<ans;

}