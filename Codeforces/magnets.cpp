#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=1;
    string prev, curr;
    cin>>prev;
    for(int i=1; i<n; i++)
    {
        cin>>curr;
        if(prev!=curr)
        {
            ans++;
        }
        prev=curr;
    }
    cout<<ans<<endl;
}