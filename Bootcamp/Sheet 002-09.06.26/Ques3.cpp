#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<long long, long long> freq;
    long long diff = 0;
    long long ans = 0;
    freq[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            diff++;
        }
        else if (s[i] == 'B')
        {
            diff--;
        }
        ans += freq[diff];
        freq[diff]++;
    }
    cout << ans << endl;
    return 0;
}