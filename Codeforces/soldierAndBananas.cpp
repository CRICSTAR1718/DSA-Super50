#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k, n, w;
    cin >> k >> n >> w;

    long long totalCost = k * w * (w + 1) / 2;
    long long borrow = totalCost - n;

    cout << max(0LL, borrow) << endl;
    return 0;
}