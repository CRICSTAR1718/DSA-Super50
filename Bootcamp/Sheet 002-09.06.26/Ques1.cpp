#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long q;
    cin >> q;
    vector<vector<long long>> freq(n, vector<long long>(26));
    for (long long i = 0; i < n; i++)
    {
        if (i > 0)
        {
            freq[i] = freq[i - 1];
        }
        char ch = s[i];
        freq[i][ch - 'a']++;
    }
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l > 0)
        {
            vector<long long> left = freq[l - 1];
            vector<long long> right = freq[r];

            bool flag = true;
            bool first = false;
            if ((r - l + 1) % 2)
            {
                first = true;
            }
            for (int i = 0; i < 26; i++)
            {
                if ((right[i] - left[i]) % 2)
                {
                    if (first)
                    {
                        first = false;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            vector<long long> right = freq[r];
            bool flag = true;
            bool first = false;
            if ((r - l + 1) % 2)
            {
                first = true;
            }
            for (int i = 0; i < 26; i++)
            {
                if (right[i] % 2)
                {
                    if (first)
                    {
                        first = false;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}