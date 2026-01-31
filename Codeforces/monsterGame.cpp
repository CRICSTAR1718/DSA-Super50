#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long>a(n);
        vector<long long>b(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        sort(a.begin(), a.end(), greater<long long>());
        vector<long long>prefSum(n);
        prefSum[0]=b[0];
        for(int i=1; i<n; i++)
        {
            prefSum[i]=prefSum[i-1]+b[i];
        }
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            long long x=a[i];
            long long swords=i+1;
            int k=upper_bound(prefSum.begin(), prefSum.end(), swords) - prefSum.begin();
            ans=max(ans, x*k);
        }
        cout<<ans<<endl;
    }
}