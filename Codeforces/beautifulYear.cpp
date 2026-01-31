#include <bits/stdc++.h>
using namespace std;
bool distinctDigits(int year) {
    string s = to_string(year);
    set<char> st(s.begin(), s.end());
    return st.size() == 4;
}
int main() {
    int y;
    cin >> y;
    for (int year = y + 1; ; year++) {
        if (distinctDigits(year)) {
            cout << year << endl;
            break;
        }
    }
    return 0;
}
