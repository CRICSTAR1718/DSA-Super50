#include<bits/stdc++.h>
using namespace std;

void printSubset(vector<int> &arr, int n, int i, vector<int>&curr, vector<vector<int>>&res)
{
    if(i==n)
    {
        res.push_back(curr);
        return;
    }
    // Pick
    curr.push_back(arr[i]);
    printSubset(arr, n, i + 1, curr, res);
    
    // Not Pick
    curr.pop_back();
    printSubset(arr, n, i + 1, curr, res);
}
int main()
{
    int n;
    cout << "Enter Size of array: " << endl;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> res;
    vector<int> curr;
    cout << "Enter elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printSubset(arr, n, 0, curr, res);
    cout << "The Subsets are: " << endl;
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}