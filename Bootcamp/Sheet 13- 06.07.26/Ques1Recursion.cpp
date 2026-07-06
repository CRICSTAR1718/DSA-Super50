#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &arr, int idx)
{
    if (idx <= 0)
    {
        return 0;
    }
    if (idx == 1)
    {
        return abs(arr[1] - arr[0]);
    }
    return min((helper(arr, idx - 1) + abs(arr[idx] - arr[idx - 1])), (helper(arr, idx - 2) + abs(arr[idx] - arr[idx - 2])));
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << helper(arr, n - 1) << endl;
    return 0;
}