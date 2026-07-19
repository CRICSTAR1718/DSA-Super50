#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isPalindrome(string &s, int l, int r, vector<vector<int>> &dp)
{
    if (l >= r)
        return true;
    if (dp[l][r] != -1)
        return dp[l][r];
    if (s[l] != s[r])
        return dp[l][r] = false;
    return dp[l][r] = isPalindrome(s, l + 1, r - 1, dp);
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j, dp))
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}