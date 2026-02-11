#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // 1--->prime
    // 2--->composite
    if(n<=2)
    {
        cout << "1" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "1" << " ";
        }
        cout << endl;
    }
    else{
        cout << "2" << endl;
        vector<int> arr(n + 2, 1);
        for (int i = 2; i*i <= n+1; i++)
        {
            if (arr[i] == 1)
            {
                for (long long j = 1LL*i * i; j <= n+1; j+=i)
                {
                    arr[j] = 2;
                }
            }
        }
        for (int i = 2; i <= n+1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
}