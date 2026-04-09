#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans=-1;
    for (int i = 0; i < 31; i++)
    {
        if (n & (1 << i))
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}