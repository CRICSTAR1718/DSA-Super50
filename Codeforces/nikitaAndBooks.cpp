#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> books(n);
        for (int i = 0; i < n; i++)
        {
            cin >> books[i];
        }
        long long extraBooks = 0;
        bool possible = true;
        for (int idx = 0; idx < n; idx++)
        {
            long long currentBooks = books[idx] + extraBooks;
            long long requiredBooks = idx + 1;
            if (currentBooks < requiredBooks)
            {
                possible = false;
                break;
            }
            extraBooks = currentBooks - requiredBooks;
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}