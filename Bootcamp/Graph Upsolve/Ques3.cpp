#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int firstU, firstV;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (i == 0)
        {
            firstU = u;
            firstV = v;
        }
        if (i == 1)
        {
            if (u == firstU || u == firstV)
            {
                ans = u;
            }
            else
            {
                ans = v;
            }
        }
        if (i > 1)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}