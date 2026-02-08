#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>arr(n);
    vector<long long>prefSum(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            prefSum[i]=arr[i];
        }
        else{
            prefSum[i]=prefSum[i-1]+arr[i];
        }
    }
    vector<long long>prefSumSorted(n);
    sort(arr.begin(), arr.end());
    prefSumSorted[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        prefSumSorted[i]=prefSumSorted[i-1]+arr[i];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int t, l, r;
        cin>>t>>l>>r;
        l--; r--;
        if(t==1)
        {
            if(l==0)
            {
                cout<<prefSum[r]<<endl;
            }
            else{
                cout<<prefSum[r]-prefSum[l-1]<<endl;
            }
            
        }
        else{
            if(l==0)
            {
                cout<<prefSumSorted[r]<<endl;
            }
            else{
                cout<<prefSumSorted[r]-prefSumSorted[l-1]<<endl;
            }
        }
    }
}