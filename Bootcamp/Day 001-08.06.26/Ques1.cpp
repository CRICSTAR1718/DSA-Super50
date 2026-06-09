#include <bits/stdc++.h>
using namespace std;
void generate(int n, int open, int close, string s)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }
    if (open < n / 2)
    {
        generate(n, open + 1, close, s + "(");
    }
    if (close < open)
    {
        generate(n, open, close + 1, s + ")");
    }
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << 0 << endl;
    }
    else
    {
        generate(n, 0, 0, "");
    }

    return 0;
}