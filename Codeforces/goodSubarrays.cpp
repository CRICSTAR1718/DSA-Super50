#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<long long, long long> mpp;
        long long curSum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int val = (s[i] - '0') - 1;
            curSum += val;
            if(curSum==0){
                ans++;
            }
            if (mpp.find(curSum) != mpp.end()) {
                ans += mpp[curSum];
            }
            mpp[curSum]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
