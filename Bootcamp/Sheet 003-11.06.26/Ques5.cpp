#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    long long l;
    cin >> l;
    string s;
    cin >> s;
    bool flag = true;
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            c++;
        }
        else
        {
            c = 1;
        }
        if (c > l)
        {
            flag = false;
            break;
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
    return 0;
}