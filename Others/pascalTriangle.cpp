#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<long long>> pascal(n + 1, vector<long long>(m+1, 0));
    pascal[0][0] = 1;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(j==0 || j==i)
            {
                pascal[i][j] = 1;
            }
            else{
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
}