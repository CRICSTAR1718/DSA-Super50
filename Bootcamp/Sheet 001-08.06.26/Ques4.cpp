#include <bits/stdc++.h>
using namespace std;
void genarate(vector<int> &arr, int n, int i, string s, bool &flag, long long target, long long curr, string &ans)
{
    if (flag)
    {
        return;
    }
    if (curr == target && i == n)
    {
        ans = s;
        flag = true;
        return;
    }
    if (i == n)
    {
        return;
    }
    genarate(arr, n, i + 1, s + "*", flag, target, curr * arr[i], ans);
    genarate(arr, n, i + 1, s + "+", flag, target, curr + arr[i], ans);
    genarate(arr, n, i + 1, s + "-", flag, target, curr - arr[i], ans);
}
int main()
{
    // your code goes here
    int n;
    long long t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool flag = false;
    string s = "";
    string ans = "";
    genarate(arr, n, 1, s, flag, t, arr[0], ans);
    if (flag)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}