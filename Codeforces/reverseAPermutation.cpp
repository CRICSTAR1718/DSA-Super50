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
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<int>suffMax(n);
        suffMax[n-1]=a[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suffMax[i]=max(suffMax[i+1], a[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(suffMax[i]>a[i])
            {
                for(int j=n-1; j>i; j--)
                {
                    if(a[j]==suffMax[i])
                    {
                        reverse(a.begin()+i, a.begin()+j+1);
                        i=n;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}