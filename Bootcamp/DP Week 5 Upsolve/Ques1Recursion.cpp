#include <bits/stdc++.h>
using namespace std;
int helper(int idx, vector<int> &S, vector<int> &C)
{
    if (idx < 0)
    {
        return 0;
    }
    if (idx == 0)
    {
        return S[0];
    }
    int single = S[idx] + helper(idx - 1, S, C);
    int combo = C[idx - 1] + helper(idx - 2, S, C);
    return min(single, combo);
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<int> S(n);
    vector<int> C(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        cin >> C[j];
    }
    cout << helper(n - 1, S, C) << endl;
    return 0;
}