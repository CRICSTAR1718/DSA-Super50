// Problem Statement : Generate All Combinations with At Most Two Occurrences
// You are given an array arr of N integers.
// For each element in the array,
// you can :
// Include it 0 times
// Include it 1 time
// Include it 2 times
// Your task is to generate and print all possible combinations that can be formed using this rule.
// Each combination should preserve the original order of elements.

#include <bits/stdc++.h>
    using namespace std;
void find(vector<int> &arr, int idx, int curr[], vector<vector<int>> &res, int count)
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
    // Take 1
    curr[count] = arr[idx];
    find(arr, idx + 1, curr, res, count + 1);
    // Take 2
    curr[count] = arr[idx];
    curr[count + 1] = arr[idx];
    find(arr, idx + 1, curr, res, count + 2);
    // Not Take
    find(arr, idx + 1, curr, res, count);
}
void print(vector<int> &curr)
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
    int curr[2*n];
    find(arr, 0, curr, res, 0);
    cout << "The possible combinations are: " << endl;
    for (auto it : res)
    {
        print(it);
    }
}


