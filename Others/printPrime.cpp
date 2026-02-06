//Sieve of Eratosthenes
// OPTIMAL Approach
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<bool>arr(n+1, true);
    arr[0]=false;
    arr[1]=false;
    for(int i=2; i*i<=n; i++)
    {
        if(arr[i])
        {
            for(int j=i*i; j<=n; j+=i)
            {
                arr[j]=false;
            }
        }
    }
    for(int i=0; i<=n; i++)
    {
        if(arr[i]==true)
        {
            cout<<i<<" ";
        }
    }
}


// BETTER APPROACH
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     vector<bool>arr(n+1, true);
//     arr[0]=false;
//     arr[1]=false;
//     for(int i=2; i<=n; i++)
//     {
//         if(arr[i])
//         {
//             for(int j=2*i; j<=n; j+=i)
//             {
//                 arr[j]=false;
//             }
//         }
//     }
//     for(int i=0; i<=n; i++)
//     {
//         if(arr[i]==true)
//         {
//             cout<<i<<" ";
//         }
//     }
// }

// BRUTE FORCE
// #include<bits/stdc++.h>
// using namespace std;
// bool isPrime(int n)
// {
//     if(n<2)
//     {
//         return false;
//     }
//     for(int i=2; i*i<=n; i++)
//     {
//         if(n%i==0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=2; i<=n; i++)
//     {
//         if(isPrime(i))
//         {
//             cout<<i<<" ";
//         }
//     }
// }