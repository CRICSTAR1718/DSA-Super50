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
        int count0s=0;
        int count1s=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]==0)
            {
                count0s++;
            }
            else if(a[i]==1)
            {
                count1s++;
            }
        }
        if(count0s==0)
        {
            cout<<"No"<<endl;
        }
        else if(count0s==1)
        {
            cout<<"Yes"<<endl;
        }
        else if(count1s==0)
        {
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}