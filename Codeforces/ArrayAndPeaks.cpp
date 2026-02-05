#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        if(k >((n-1)/2))
        {
            cout<<-1<<endl;
            continue;
        }
        vector<int>big;
        vector<int>small;
        for(int i=n; i>=n-k+1; i--){
            big.push_back(i);
        }
        for(int i=1; i<=n-k; i++){
            small.push_back(i);
        }
        vector<int>ans;
        int i=0;
        int j=0;
        while(j<k)
        {
            ans.push_back(small[i++]);
            ans.push_back(big[j++]);
        }
        while(i<small.size())
        {
            ans.push_back(small[i++]);
        }
        for(int x: ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}