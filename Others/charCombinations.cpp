#include <bits/stdc++.h>
using namespace std;
void find(vector<int> &arr, int idx, string curr, vector<vector<int>> &res, int count)
{
    if (idx == arr.size())
    {
        vector<int> v;
        for (int i = 0; i < count; i++)
        {
            v.push_back(curr[i]);
        }
        res.push_back(v);
        return;
    }
    // Take 
    curr+=arr[idx];
    find(arr, idx + 1, curr, res, count + 1);
    // Not Take
    find(arr, idx + 1, curr, res, count);
}
void print(string curr)
{
    cout << curr;
}
int main()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<string> res;
    string curr = "";
    find(arr, 0, curr, res, 0);
    cout << "The possible combinations are: " << endl;
    for (auto it : res)
    {
        print(it);
    }
}