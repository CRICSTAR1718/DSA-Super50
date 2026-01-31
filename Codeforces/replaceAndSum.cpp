#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,q;
        cin>>n>>q;
        vector<long long> a(n);
        vector<long long>b(n);
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(long long i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<long long>suffixMax(n);
        suffixMax[n-1]=b[n-1];
        for(long long i=n-2;i>=0;i--)
        {
            suffixMax[i]=max(suffixMax[i+1],b[i]);
        }
        vector<long long>prefixSum(n);
        prefixSum[0]=suffixMax[0];
        for(long long i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1]+suffixMax[i];
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            if(l==0)
            {
                cout<<prefixSum[r]<<" ";
            }
            else
            {
                cout<<prefixSum[r]-prefixSum[l-1]<<" ";
            }
        }
        cout<<endl;
    }
}