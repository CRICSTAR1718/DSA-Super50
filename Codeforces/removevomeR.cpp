// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         int count0 = 0;
//         int count1 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if(s[i]=='0')
//             {
//                 count0++;
//             }
//             else{
//                 count1++;
//             }
//         }
//         if(count0==0 || count1 ==0)
//         {
//             cout << 1 << endl;
//         }
//         else if(min(count0,count1)==1)
//         {
//             cout << 2 << endl;
//         }
//         else{
//             cout << 1 << endl;
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
        int n;
        string s;
        cin >> n >> s;

        int blocks = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
                blocks++;
        }

        if (blocks == 2)
            cout << 2 << "\n";
        else
            cout << 1 << "\n";
    }
    return 0;
}