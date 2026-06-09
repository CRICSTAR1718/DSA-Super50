#include <bits/stdc++.h>
using namespace std;
void generate(vector<int> &arr, int n, int i, vector<int> &curr, vector<vector<int>> &res)
{
    if (n == i)
    {
        res.push_back(curr);
        return;
    }
    // pick
    curr.push_back(arr[i]);
    generate(arr, n, i + 1, curr, res);

    // not pick
    curr.pop_back();
    generate(arr, n, i + 1, curr, res);
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> curr;
    vector<vector<int>> res;
    generate(arr, n, 0, curr, res);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}