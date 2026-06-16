#include <bits/stdc++.h>
using namespace std;
void generate(int i, int n, string &curr, string &s, vector<string> &res, vector<string> &mpp)
{
    if (i == n)
    {
        res.push_back(curr);
        return;
    }
    int d = s[i] - '0';
    for (char &ch : mpp[d])
    {
        curr.push_back(ch);
        generate(i + 1, n, curr, s, res, mpp);
        curr.pop_back();
    }
}
int main()
{
    // your code goes here
    string s;
    cin >> s;
    vector<string> mpp = {"", "TI", "XYZ", "ABC", "MNO", "PQR", "EFG", "UVW", "JKL", "DSH"};
    string curr = "";
    vector<string> res;
    generate(0, s.size(), curr, s, res, mpp);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}