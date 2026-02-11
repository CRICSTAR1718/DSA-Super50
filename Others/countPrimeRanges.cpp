#include <bits/stdc++.h>
using namespace std;
vector<int> find(int n)
{
    vector<bool> arr(n + 1, true);
    vector<int> ans;
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
        {
            ans.push_back(i); 
        }
    }
    return ans;
}
int main()
{
    int l, r;
    cin >> l >> r;
    vector<int> primesTillrootR = find((int)sqrt(r));
    // segmented array for range [l, r]
    vector<bool> isPrime(r - l + 1, true);
    if (l == 0)
    {
        isPrime[0] = false;
        if (r >= 1)
            isPrime[1 - l] = false;
    }
    if (l == 1)
    {
        isPrime[0] = false;
    }
    for (int p : primesTillrootR)
    {
        long long start = max(1LL * p * p,((l + p - 1) / p) * 1LL * p);
        for (long long j = start; j <= r; j += p)
        {
            isPrime[j - l] = false;
        }
    }
    for (int i = 0; i <= r - l; i++)
    {
        if (isPrime[i])
            cout << (i + l) << " ";
    }
}