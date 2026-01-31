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
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int maxElement = INT_MIN;
        int idx = -1;
        for(int i=0; i<n; i++)
        {
            if(a[i] > maxElement)
            {
                maxElement = a[i];
                idx = i;
            }
        }
        swap(a[0], a[idx]);
        vector<int> prefixMax(n);
        prefixMax[0] = a[0];    
        for(int i=1; i<n; i++)
        {
            prefixMax[i] = max(prefixMax[i-1], a[i]);
        }
        int maxSum=0;
        for(int num: prefixMax)
        {
            maxSum += num;
        }
        cout<<maxSum<<endl;
    }
}