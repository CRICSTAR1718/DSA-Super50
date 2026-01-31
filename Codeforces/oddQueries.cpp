#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    // Input number of test cases
    cin>>t;
    while(t--)
    {
        int n,q;
        // Input length of array and number of queries;
        cin>>n>>q;
        // Input array
        vector<int>arr(n);
        vector<int>prefSum(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        // Prefix Sum
        prefSum[0]=arr[0];
        for(int i=1; i<n; i++)
        {
            prefSum[i]=prefSum[i-1]+arr[i];
        }
        int sum=prefSum[n-1];
        while(q--)
        {
            int l,r, k;
            // Input left and right indices of query and value of k
            cin>>l>>r>>k;
            // Converting to 0-based indexing
            l--;
            r--;
            int oldSegment=prefSum[r]-((l>0)?prefSum[l-1]:0);
            int newSegment=((r-l)+1)*k;
            int newSum=sum-oldSegment+newSegment;
            
            // Check if newSum is odd or even
            if(newSum%2==0)
            {
                // Even Sum
                cout<<"No"<<endl;
            }
            else
            {
                // Odd Sum
                cout<<"Yes"<<endl;
            }
        }
    }
}