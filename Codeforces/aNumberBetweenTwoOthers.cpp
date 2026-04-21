#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long x, y;
        cin >> x >> y;
        long long z=y/x;
        if(z!=2)
        {
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}