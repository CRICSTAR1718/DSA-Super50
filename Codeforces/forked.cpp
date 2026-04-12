#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int kx, ky;
        cin >> kx >> ky;
        int qx, qy;
        cin >> qx >> qy;
        int count = 0;
        vector<pair<int, int>> directions = {{a, b}, {a, -b}, {-a, +b}, {-a, -b}, {b, a}, {-b, a}, {b, -a}, {-b, -a}};
        set<pair<int, int>> king;
        set<pair<int, int>> queen;
        for(auto &it : directions)
        {
            king.insert({kx + it.first, ky + it.second});
        }
        for(auto &it: directions)
        {
            queen.insert({qx + it.first, qy + it.second});
        }
        for(auto &it: king)
        {
            if(queen.count(it))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}