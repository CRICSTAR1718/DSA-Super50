#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    string s;
    cin >> s;
    int n = s.size();
    int countX = 0;
    int countY = 0;
    int countZ = 0;
    int left = 0;
    long long ans = 0;
    for (int right = 0; right < n; right++)
    {
        if (s[right] == 'X')
        {
            countX++;
        }
        else if (s[right] == 'Y')
        {
            countY++;
        }
        else
        {
            countZ++;
        }
        while (countX >= 1 && countY >= 1 && countZ >= 1)
        {
            ans += (n - right);
            if (s[left] == 'X')
            {
                countX--;
            }
            else if (s[left] == 'Y')
            {
                countY--;
            }
            else
            {
                countZ--;
            }
            left++;
        }
    }
    cout << ans << endl;
    return 0;
}