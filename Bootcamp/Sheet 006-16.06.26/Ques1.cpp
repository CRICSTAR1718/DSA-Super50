#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
void generate(int i, int n, string &s, string curr, vector<string> &res)
{
    if (i == n)
    {
        res.push_back(curr);
        return;
    }
    if (isVowel(s[i]))
    {
        generate(i + 1, n, s, curr + s[i], res);
    }
    else
    {
        generate(i + 1, n, s, curr + " " + s[i], res);
        generate(i + 1, n, s, curr + s[i], res);
    }
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> res;
    generate(0, s.size(), s, "", res);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}