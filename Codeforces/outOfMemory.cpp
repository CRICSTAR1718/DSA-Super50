#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m,h;
        cin>>n>>m>>h;
        vector<long long> a(n);
        vector<long long> originalValues(n);
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
            originalValues[i]=a[i];
        }
        while(m--)
        {
            long long b;
            long long c;
            cin>>b>>c;
            a[b-1]+=c;
            if(a[b-1]>h)
            {
               a=originalValues;
            }
        }
        for(long long i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}








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