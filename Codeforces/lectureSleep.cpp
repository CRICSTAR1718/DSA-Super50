#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    // Input number of lectures and sleep duration
    cin >> n >> k;
    vector<int> theorems(n);
    for (int i = 0; i < n; i++)
    {
        // Input number of theorems in each minute
        cin >> theorems[i];
    }
    vector<int>sleepAwake(n);
    vector<int> prefSum(n);
    int currSum=0, sleep=0;
    for(int i=0; i<n; i++)
    {
        cin>>sleepAwake[i];
        if(sleepAwake[i]==1)
        {
            currSum+=theorems[i];
        }
        else{
            sleep+=theorems[i];
        }
        prefSum[i]=sleep;
    }
    
    int ans=currSum;
    ans = max(ans, currSum + prefSum[k - 1]);
    for(int i=k; i<n; i++)
    {
        ans=max(ans, prefSum[i]-prefSum[i-k]+currSum);
    }
    cout<<ans<<endl;
}