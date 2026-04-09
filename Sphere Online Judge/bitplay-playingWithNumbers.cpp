// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         n--;
//         int ans = -1;
//         while(n>0)
//         {
//             int count = 0;
//             for (int i = 0; i < 31; i++)
//             {
//                 if (n & (1 << i))
//                 {
//                     count++;
//                 }
//             }
//             if(count==k)
//             {
//                 ans = n;
//                 break;
//             }
//             n = n - 2;
//         }
//         cout << ans << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        n--;
        int ans = -1;
        while (n > 0)
        {
            int count = 0;
            for (int i = 0; i < 31; i++)
            {
                if (n & (1 << i))
                {
                    count++;
                }
            }
            if (count == k)
            {
                ans = n;
                break;
            }
            n = n - 2;
        }
        cout << ans << endl;
    }
}