#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long h;
        cin >> n >> m >> h;
        vector<long long> base(n);
        for (int i = 0; i < n; i++)
            cin >> base[i];
        vector<long long> add(n, 0);
        vector<int> last_reset(n, 0);
        int current_reset = 1;
        while (m--)
        {
            int b;
            long long c;
            cin >> b >> c;
            b--;
            if (last_reset[b] != current_reset)
            {
                add[b] = 0;
                last_reset[b] = current_reset;
            }
            add[b] += c;
            if (base[b] + add[b] > h)
            {
                current_reset++; // Lazy reset
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (last_reset[i] != current_reset)
                cout << base[i] << " ";
            else
                cout << base[i] + add[i] << " ";
        }
        cout << "\n";
    }
}

// TLE
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         long long n,m,h;
//         cin>>n>>m>>h;
//         vector<long long> a(n);
//         vector<long long> addi(n,0);
//         for(long long i=0;i<n;i++)
//         {
//             cin>>a[i];
//         }
//         while(m--)
//         {
//             long long b;
//             long long c;
//             cin>>b>>c;
//             if(a[b-1]+c>h)
//             {
//                 for(int i=0;i<n;i++)
//                 {
//                     addi[i]=0;
//                 }
//             }
//             else
//             {
//                 addi[b-1]+=c;
//             }
//         }
//         for(long long i=0;i<n;i++)
//         {
//             cout<<a[i]+addi[i]<<" ";
//         }
//         cout<<endl;
//     }
// }