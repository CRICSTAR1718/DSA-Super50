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
        vector<int>ans;
        int o=n;
        int place=1;
        while(n!=0)
        {
            int d=n%10;
            if(d!=0)
            {
                ans.push_back(d*place);
            }
            place*=10;
            n=n/10;
        }
        cout<<ans.size()<<endl;
        for(int x: ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}