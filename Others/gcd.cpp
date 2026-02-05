#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter any two numbers: ";
    cin>>a>>b;
    int rem=INT_MAX;
    int divident=max(a,b);
    int divisor=min(a,b);
    while(rem!=0)
    {
        rem=divident%divisor;
        if(rem>0)
        {
            divident=divisor;
            divisor=rem;
        }
    }
    cout<<"The GCD of two numbers is: "<<divisor<<endl;
}