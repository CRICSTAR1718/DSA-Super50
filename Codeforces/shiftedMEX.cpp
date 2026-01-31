#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int best_mex=1;
        int curr=1;
        int l=0;
        sort(a.begin(),a.end());
        for(int i=0; i<n; i++)
        {
            if(a[i]!=a[i+1])
            {
                a[l] = a[i];
                l++;
            }
        }
        for(int i=0;i<a.size();i++)
        {
            if(a.size()==1)
            {
                if(a[0]!=1)
                {
                    best_mex=2;
                }
                else
                {
                    best_mex=1;
                    break;
                }
            }
            if(a[i]>=curr && a[i]==i+1)
            {
                best_mex=max(best_mex,curr);
                curr++;
            }
        }
        cout<<best_mex<<endl;
    }
}