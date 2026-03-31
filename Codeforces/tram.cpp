#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a, b;
    int current = 0;
    int max_capacity = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        current -= a; // passengers exit
        current += b; // passengers enter
        if (current > max_capacity)
        {
            max_capacity = current;
        }
    }
    cout << max_capacity << endl;
    return 0;
}