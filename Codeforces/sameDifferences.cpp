#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Input number of test cases
    int t;
    cin>>t;
    while(t--)
    {
        // Input size of array
        int n;
        cin>>n;
        // Input array
        vector<long long>a(n);
        map<long long,long long>mpp;
        //  key: a[i]-i, value= freq
        // Given eq: a[j]-a[i]==j-i =>a[j]-j =a[i]-i homogenous 
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            mpp[a[i]-i]++;
        }
        long long count=0;
        for(auto &it:mpp)
        {
            long long k=it.second;
            count+=(k*(k-1)/2);
        }
        cout<<count<<endl;
    }
}