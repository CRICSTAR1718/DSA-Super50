#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int policeRecruit=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x>-1)
        {
            policeRecruit+=x;
        }
        if(x==-1 && policeRecruit==0)
        {
            ans++;
        }
        else if(x==-1 && policeRecruit>0)
        {
            policeRecruit-=1;
        }
    }
    cout<<ans<<endl;
}