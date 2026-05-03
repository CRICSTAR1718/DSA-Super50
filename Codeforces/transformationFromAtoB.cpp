// RECURSIVE SOLUTION (MEMORY LIMIT EXCEEDED)

// #include<bits/stdc++.h>
// using namespace std;
// bool solve(int a, int b, vector<int>&curr)
// {
//     if(a==b)
//     {
//         curr.push_back(a);
//         return true;
//     }
//     if (a > b)
//     {
//         return false;
//     }
//     curr.push_back(a);
//     if (solve(a*2, b, curr))
//     {
//         return true;
//     }
//     if (solve(a*10+1, b, curr))
//     {
//         return true;
//     }
//     curr.pop_back();
//     return false;
// }

// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     vector<int> curr;
//     if (solve(a, b, curr))
//     {
//         cout << "YES\n";
//         cout<<curr.size()<<"\n";
//         for(int i=0;i<curr.size();i++)
//         {
//             cout << curr[i] << " ";
//         }
//         cout << "\n";
//     }
//     else
//     {
//         cout << "NO\n";
//     }
// }


// OPTIMAL SOLUTION
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> path;
    while (b > a)
    {
        path.push_back(b);
        if (b % 10 == 1)
        {
            b = (b - 1) / 10;
        }
        else if (b % 2 == 0)
        {
            b /= 2;
        }
        else
        {
            break;
        }
    }
    if (b == a)
    {
        path.push_back(a);
        reverse(path.begin(), path.end());
        cout << "YES\n";
        cout << path.size() << "\n";
        for (int x : path)
            cout << x << " ";
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}