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
        vector<pair<int, int> >arr(n);   
        // 0- red color 
        // 1- blue color
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].first;
            if(i%2==0)
            {
                arr[i].second=0;
            }
            else
            {
                arr[i].second=1;
            }
        }
        sort(arr.begin(), arr.end());
        bool flag=true;
        for(int i=1;i<n;i++)
        {
            if(arr[i].second==arr[i-1].second)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}