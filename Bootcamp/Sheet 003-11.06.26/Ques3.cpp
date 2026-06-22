#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n;
    cin >> n;
    long long curr = 0;
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        curr += x;
        ans = max(ans, curr);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    cout << ans << endl;
    return 0;
}