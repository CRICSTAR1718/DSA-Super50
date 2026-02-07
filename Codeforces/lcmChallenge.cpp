#include<bits/stdc++.h>
using namespace std;
long long findLCM(long long a, long long b)
{
    return (a/__gcd(a,b)*b);
} 
int main()
{
    long long n;
    cin>>n;
    if(n<=2)
    {
        cout<<2<<endl;
    }
    else if(n%2==1)
    {
        cout<<n*(n-1)*(n-2)<<endl;
    }
    else{
        long long option1=findLCM(n , findLCM(n-1, n-2));
        long long option2=findLCM(n-1 , findLCM(n-2, n-3));
        cout<<max(option1, option2);
    }
    return 0;
}
