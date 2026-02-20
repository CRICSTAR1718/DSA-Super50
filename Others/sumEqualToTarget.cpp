// An element can be taken only once
#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &arr, int idx,int target)
{
    if(idx==arr.size())
    {
        if(target==0)
        {
            return 1;
        }
        return 0;
    }
    return find(arr, idx + 1, target - arr[idx]) + find(arr, idx + 1, target);
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
    int target;
    cin >> target;
    cout<<find(arr, 0,target)<<endl;
}


// // An element can be taken infinite number of times all elements are strictly positive 
// #include <bits/stdc++.h>
// using namespace std;
// int find(vector<int> &arr, int idx, int target)
// {
//     if(target==0)
//     {
//         return 1;
//     }
//     if(target<0)
//     {
//         return 0;
//     }
//     if(idx==arr.size())
//     {
//         return 0;
//     }
//     return find(arr, idx, target - arr[idx]) + find(arr, idx + 1, target);
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
//     int target;
//     cin >> target;
//     cout << find(arr, 0, target) << endl;
// }