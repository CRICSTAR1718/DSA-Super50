// #include<bits/stdc++.h>
// using namespace std;
// int binPw(int base, int power)
// {
//     int ans = 1;
//     while(power>0)
//     {
//         if(power%2)
//         {
//             ans = ans * base;
//         }
//         base = base * base;
//         power >>= 1;
//     }
//     return ans;
// }
// int main()
// {
//     int x, p;
//     cin>>x>>p;
//     cout << binPw(x, p) << endl;
// }

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int binPw(int base, int power)
{
    int ans = 1;
    while (power > 0)
    {
        if (power % 2)
        {
            ans = ans * base;
        }
        base = base * base;
        power >>= 1;
    }
    return ans;
}
int main()
{
    int x, p;
    cin >> x >> p;
    cout << binPw(x, p) << endl;
}