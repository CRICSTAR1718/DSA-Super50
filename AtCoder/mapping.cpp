#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        s.insert(f[i]);
    }
    if(s.size()==n)
    {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    if(s.size()==m)
    {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}