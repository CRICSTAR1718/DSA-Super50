#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, a, b;
        cin >> a >> b >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long ans=b;
        for (int i = 0; i < n; i++)
        {
            ans += min(arr[i], a - 1);
        }
        cout << ans << endl;
    }
}