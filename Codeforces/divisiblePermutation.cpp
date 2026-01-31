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
        vector<int>p(n+1);
        set<int>available;
        for(int i=1; i<=n; i++)
        {
            available.insert(i);
        }
        p[n]=*available.begin();
        available.erase(p[n]);
        for(int i=n-1; i>=1; i--)
        {
            for(int x: available)
            {
                if(abs(x-p[i+1])%i==0)
                {
                    p[i]=x;
                    available.erase(x);
                    break;
                }
            }
        }
        for(int i=1; i<=n;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}