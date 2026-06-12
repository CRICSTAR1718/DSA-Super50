#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        bool ok = false;

        long long na = 2 * b - c;
        if (na > 0 && na % a == 0)
            ok = true;

        long long nb = a + c;
        if (nb % 2 == 0)
        {
            nb /= 2;
            if (nb > 0 && nb % b == 0)
                ok = true;
        }

        long long nc = 2 * b - a;
        if (nc > 0 && nc % c == 0)
            ok = true;

        cout << (ok ? "YES" : "NO") << '\n';
    }
}



