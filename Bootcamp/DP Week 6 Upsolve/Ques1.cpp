#include <bits/stdc++.h>
using namespace std;
int fun(int i, int j, string &s1, string &s2, string &s3,
        vector<vector<int>> &dp)
{
    if (i == s1.size() && j == s2.size())
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int k = i + j;
    bool ans = false;
    if (i < s1.size() && s1[i] == s3[k])
        ans |= fun(i + 1, j, s1, s2, s3, dp);
    if (j < s2.size() && s2[j] == s3[k])
        ans |= fun(i, j + 1, s1, s2, s3, dp);
    return dp[i][j] = ans;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s1.size() + s2.size() != s3.size())
    {
        cout << 0;
        return 0;
    }
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << fun(0, 0, s1, s2, s3, dp);
    return 0;
}