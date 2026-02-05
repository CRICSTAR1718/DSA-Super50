//BRUTE FORCE:

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int a, b;
//     cin>>a>>b;
//     int ans=0;
//     for(int i=max(a,b); i<=a*b; i++)
//     {
//         if(i%a==0 && i%b==0)
//         {
//             ans=i;
//             break;
//         }
//     }
//     cout<<ans<<endl;
// }


// OPTIMAL APPROACH
// GCD(a, b) * LCM(a, b)=a*b

#include<bits/stdc++.h>
using namespace std;
int findGcd(int a, int b)
{
    int rem=INT_MAX;
    int divident=max(a,b);
    int divisor=min(a,b);
    if(a==0 || b==0)
    {
        return max(a,b);
    }
    else{
        while(rem!=0)
        {
            rem=divident%divisor;
            if(rem>0)
            {
                divident=divisor;
                divisor=rem;
            }
        }
        return divisor;
    }
}
int main()
{
    int a,b; 
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    int gcd=findGcd(a,b);
    int lcm=(a*b)/gcd;
    cout<<"LCM: "<<lcm<<endl;
}
