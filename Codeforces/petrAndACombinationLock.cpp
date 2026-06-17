#include<bits/stdc++.h>
using namespace std;
void check(int i, int n, bool &flag, vector<int>&arr, int curr)
{
    if(i==n)
    {
        if(curr%360==0)
        {
            flag = true;
        }
        return;
    }
    check(i + 1, n, flag, arr, curr + arr[i]);
    check(i + 1, n, flag, arr, curr - arr[i]);
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
    bool flag = false;
    check(0, n, flag, arr, 0);
    if(flag)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}