#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, x;
        cin >> a >> b >> x;
        vector<long long> A, B;
        while (true)
        {
            A.push_back(a);
            if (a == 0)
                break;
            a /= x;
        }
        while (true)
        {
            B.push_back(b);
            if (b == 0)
                break;
            b /= x;
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                ans = min(ans, 1LL * i + j + llabs(A[i] - B[j]));
            }
        }
        cout << ans << "\n";
    }
}