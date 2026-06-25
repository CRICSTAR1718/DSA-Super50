#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    long long n;
    cin >> n;
    long long start = 1;
    long long count = 9;
    long long digits = 1;
    while (n > digits * count)
    {
        n -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }
    long long num = start + (n - 1) / digits;
    long long i = (n - 1) % digits;
    string s = to_string(num);
    cout << s[i] - '0' << endl;
    return 0;
}