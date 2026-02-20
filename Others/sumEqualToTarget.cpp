#include <bits/stdc++.h>
using namespace std;
int findSubsets(vector<int> &arr, int idx,int target)
{
    if(idx==arr.size())
    {
        if(target==0)
        {
            return 1;
        }
        return 0;
    }
    return findSubsets(arr, idx + 1, target - arr[idx]) + findSubsets(arr, idx + 1, target);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout<<findSubsets(arr, 0,target)<<endl;

}