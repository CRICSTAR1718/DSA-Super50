#include<bits/stdc++.h>
using namespace std;
int main()
{
    // map<string, int>marks;
    // marks["Rahul"]=100;
    // marks["Shreya"]=80;
    // marks["Preeti"]=90;
    // marks["Rita"]=70;
    // for( auto &it: marks)
    // {
    //     cout<<it.first<<": "<<it.second<<endl;
    // }

    // Input size of array
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    // Input array
    vector<int>arr(n);
    map<int,int>mpp;
    cout<<"Enter elements of array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        mpp[arr[i]]++;
    }
    int max_freq=INT_MIN;
    int ans=INT_MIN;
    for(auto &it:mpp)
    {
        if(it.second >max_freq)
        {
            max_freq=it.second;
            ans=it.first;
        }
    }
    cout<<"Element with maximum frequency: "<<ans;
}