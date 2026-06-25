#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<pair<long long, long long>> mat;
    int m = n;
    while (m--)
    {
        long long l, r;
        cin >> l >> r;
        mat.push_back({l, r});
    }
    sort(mat.begin(), mat.end());
    long long tot = 1LL * n * (n - 1) / 2;
    long long bad = 0;
    vector<long long> ends;
    for (int i = 0; i < n; i++)
    {
        long long L = mat[i].first;
        // R<L
        bad += (lower_bound(ends.begin(), ends.end(), L)) - ends.begin();
        ends.insert(upper_bound(ends.begin(), ends.end(), mat[i].second), mat[i].second);
    }
    cout << tot - bad << endl;
    return 0;
}