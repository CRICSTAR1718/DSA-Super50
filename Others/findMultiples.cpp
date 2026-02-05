
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
int findLcm(int a, int b)
{
    int gcd=findGcd(a,b);
    int lcm=(a*b)/gcd;
    return lcm;
}

int main()
{
    int n, a,b;
    cout<<"Enter value of n then a then b: ";
    cin>>n>>a>>b;
    int count=0;
    int countA=n/a;
    int countB=n/b;
    int countAB=n/findLcm(a,b);
    int ans=countA+countB-countAB;
    cout<<"Count of common multiples: "<<ans<<endl;
}

// for three numbers a, b, c
// ans=countA+countB+countC-countAB-countBC-countCA+countABC