#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(arr[i], maxi);
            mini = min(arr[i], mini);
        }
        cout << maxi - mini + 1 << endl;
        ;
    }
}