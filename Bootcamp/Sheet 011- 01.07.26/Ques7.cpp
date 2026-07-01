#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    int j = 0;
    int ans = INT_MAX;
    while (i < n && j < m)
    {
        ans = min(ans, abs(A[i] - B[j]));
        if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}