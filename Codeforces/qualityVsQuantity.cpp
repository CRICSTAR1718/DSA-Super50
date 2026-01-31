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
        vector<long long>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        long long sumRed=0;
        long long sumBlue=0;
        bool flag=false;
        vector<long long>pref(n);
        pref[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+arr[i];
        }
        vector<long long>suff(n);
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]+arr[i];
        }
        for(int countBlue=1; countBlue<n; countBlue++)
        {
                sumBlue=pref[countBlue];
                sumRed=suff[n-(countBlue -1)];
                if(sumRed>sumBlue)
                {
                    flag=true;
                }
        }
        if(flag)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}