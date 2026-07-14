#include <bits/stdc++.h>
using namespace std;

string helper(int i, int j, string &s, string &t)
{
    if (i < 0 || j < 0)
        return "";
    if (s[i] == t[j])
        return helper(i - 1, j - 1, s, t) + s[i];
    string op1 = helper(i - 1, j, s, t);
    string op2 = helper(i, j - 1, s, t);
    return (op1.size() > op2.size()) ? op1 : op2;
}

int main()
{
    string s, t;
    cin >> s >> t;
    string ans = helper(s.size() - 1, t.size() - 1, s, t);
    cout << ans << endl;
}