// You are given q queries, each query has a number, calculate no.of factors for each number
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // your code goes here
//     int maxn = 1000000;
//     vector<int> spf(maxn + 1);
//     for (int i = 0; i <= maxn; i++)
//     {
//         spf[i] = i;
//     }
//     for (long long i = 2; i * i <= maxn; i++)
//     {
//         if (spf[i] == i)
//         {
//             for (int j = i * i; j <= maxn; j += i)
//             {
//                 if (spf[j] == j)
//                 {
//                     spf[j] = i;
//                 }
//             }
//         }
//     }
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int n;
//         cin >> n;
//         map<int, int> mpp;
//         while (n != 1)
//         {
//             int p = spf[n];
//             mpp[p]++;
//             n = n / spf[n];
//         }
//         int ans = 1;
//         for (auto it : mpp)
//         {
//             ans *= (it.second + 1);
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int maxn = 1000000;
    vector<int> spf(maxn + 1);
    for (int i = 0; i <= maxn; i++)
    {
        spf[i] = i;
    }
    for (long long i = 2; i * i <= maxn; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int last = -1;
        int ans = 1;
        int count = 0;
        while (n != 1)
        {
            int p = spf[n];
            if(p==last)
            {
                count++;
            }
            else{
                if(last!=-1)
                {
                    ans *= (count + 1);
                }
                
                count = 1;
            }
            n = n / p;
            last = p;
        }
        ans *= (count + 1);
        cout << ans << endl;
    }
    return 0;
}