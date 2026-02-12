#include <bits/stdc++.h>
using namespace std;
#define maxi 1000001
int main()
{
    vector<bool> sieve(maxi, true);
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i *i< maxi; i++)
    {
        if (sieve[i])
        {
            for (int j = i*i; j < maxi; j += i)
            {
                sieve[j]=false;
            }
        }
    }
    int n;
    cin >> n;
    while(n--)
    {
        long long x;
        cin >> x;
        long long r = sqrtl(x);
        if(r*r==x && sieve[r])
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}