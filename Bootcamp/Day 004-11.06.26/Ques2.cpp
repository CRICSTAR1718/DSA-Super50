
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n;
    cin >> n;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mpp[x]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (mpp.find(x) != mpp.end())
        {
            cout << mpp[x] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}