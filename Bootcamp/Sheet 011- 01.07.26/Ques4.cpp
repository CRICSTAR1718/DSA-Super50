#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    string s;
    cin >> s;
    long long ans = 0;
    long long n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            long long left = i + 1;
            long long right = n - i;
            ans += (left * right * 1LL);
        }
    }
    cout << ans << endl;
    return 0;
}