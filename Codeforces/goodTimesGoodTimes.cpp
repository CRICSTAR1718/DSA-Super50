// #include <bits/stdc++.h>
// using namespace std;

// bool good(long long n)
// {
//     set<int> s;
//     while (n)
//     {
//         s.insert(n % 10);
//         n /= 10;
//     }
//     return s.size() <= 2;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         long long x;
//         cin >> x;

//         for (int y = 2;; y++)
//         {
//             if (good(y) && good(x * y))
//             {
//                 cout << y << "\n";
//                 break;
//             }
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;
        int k = x.size();
        long long y = 1;
        for (int i = 0; i < k; i++){
            y *= 10;
        }  
        y += 1;
        cout << y << "\n";
    }
    return 0;
}