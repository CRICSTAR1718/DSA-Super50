#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] >= arr[k] && arr[i] > 0)
            count++;
    }
    cout << count << endl;
    return 0;
}
