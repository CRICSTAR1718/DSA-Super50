// OPTIMAL
// Complexity= O(n*log(n))
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            arr[j]++;
        }
    }
    cout<<"The count of factors are: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" "<<arr[i]<<endl;
    }
}

// BRUTE FORCE 
// Complexity= O(n*sqrt(n))
// #include<bits/stdc++.h>
// using namespace std;
// int countDiviors(int n)
// {
//     int count=0;
//     for(int i=1; i*i<=n; i++)
//     {
//         if(n%i==0)
//         {
//             count++;
//             if(n/i != i)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>arr(n+1);
//     for(int i=1; i<=n; i++)
//     {
//         arr[i]=countDiviors(i);
//     }
//     cout<<"The count of factors are: "<<endl;
//     for(int i=1; i<=n; i++)
//     {
//         cout<<i<<" "<<arr[i]<<endl;
//     }
// }