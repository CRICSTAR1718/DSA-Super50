#include <bits/stdc++.h>
using namespace std;
void findSubsets(vector<int> &arr, int idx, int curr[], vector<vector<int>> &res, int count)
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

    curr[count] = arr[idx];
    findSubsets(arr, idx + 1, curr, res, count+1);
    // Not Take
    findSubsets(arr, idx + 1, curr, res, count);
}
void printSubset(vector<int> &curr)
{
    for (auto it : curr)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> res;
    int curr[n];
    findSubsets(arr, 0, curr, res, 0);
    for (auto it : res)
    {
        printSubset(it);
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// void findSubsets(vector<int> &arr, int idx, vector<int> curr, vector<vector<int>> &res)
// {
//     if(idx==arr.size())
//     {
//         res.push_back(curr);
//         return;
//     }
//     // Take
//     curr.push_back(arr[idx]);
//     findSubsets(arr, idx + 1, curr, res);
//     curr.pop_back(); //Backtrack
//     // Not Take
//     findSubsets(arr, idx + 1, curr, res);
// }
// void printSubset(vector<int>&curr)
// {
//     for(auto it: curr)
//     {
//         cout << it << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     vector<vector<int>> res;
//     vector<int> curr;
//     findSubsets(arr, 0, curr, res);
//     for(auto it: res)
//     {
//         printSubset(it);
//     }
// }
