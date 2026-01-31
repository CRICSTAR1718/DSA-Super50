#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    unordered_set<int>s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans(n);
    for (int i = n-1; i>=0; i--) {
            s.insert(arr[i]);
            ans[i] = s.size();
    }
    while(m--) {
        int x;
        cin >> x;
        cout << ans[x - 1] << endl;
    }
}