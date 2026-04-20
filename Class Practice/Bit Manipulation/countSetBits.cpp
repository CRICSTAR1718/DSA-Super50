#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i <31; i++)
    {
        if(n & (1<<i))
        {
            count++;
        }
    }
    cout << count << endl;
}