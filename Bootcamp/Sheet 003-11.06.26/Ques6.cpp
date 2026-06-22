#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    long long n;
    cin >> n;
    set<int> st;
    for (long long i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << endl;
    return 0;
}