#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int windowSum = 0;
    for (long long i = 0; i < k; i++)
    {
        windowSum += h[i];
    }
    int minSum = windowSum;
    int startIdx = 0;
    for (long long i = k; i < n; i++)
    {
        windowSum += h[i];
        windowSum -= h[i - k];
        if (windowSum < minSum)
        {
            minSum = windowSum;
            startIdx = i - k + 1;
        }
    }
    cout << startIdx + 1 << endl;
    return 0;
}