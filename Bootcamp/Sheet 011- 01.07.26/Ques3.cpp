#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<int> arr(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans += max(left[i], right[i]);
    }

    cout << ans << endl;
    return 0;
}