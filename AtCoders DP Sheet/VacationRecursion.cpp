#include<bits/stdc++.h>
using namespace std;
int a = 0;
int b = 1;
int c = 2;
int helper(int idx, vector<vector<int>> &arr, int prev, int n)
{
    if(idx==n)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (int j = 0; j < 3; j++)
    {
        if(j!=prev)
        {
            ans = max(ans, (arr[idx][j] + helper(idx + 1, arr, j, n)));
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>>arr(n, vector<int>(3,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = helper(0, arr, 3, n);
    cout << ans << endl;
}