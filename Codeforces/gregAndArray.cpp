#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m ,k;
    cin >> n >> m >> k;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int>l(m);
    vector<int>r(m);
    vector<int>d(m);
    for (int i=0; i<m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
        l[i]--;
        r[i]--;
    }
    vector<long long>operationCount(m+1, 0);
    for(int i=0; i<k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        operationCount[x]++;
        operationCount[y+1]--;
    }
    for(int i=1; i<=m; i++)
    {
        operationCount[i] += operationCount[i-1];
    }
    vector<long long>diff(n+1, 0);
    for(int i=0; i<m; i++)
    {
        long long totalEffect = operationCount[i] * d[i];
        diff[l[i]] += totalEffect;
        diff[r[i]+1] -= totalEffect;
    }
    long long currentAdd = 0;
    for(int i=0; i<n; i++)
    {
        currentAdd += diff[i];
        arr[i] += currentAdd;
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

}