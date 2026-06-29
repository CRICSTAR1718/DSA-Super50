// SLIDING WINDOW

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // your code goes here
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     int ans = 0;
//     int left = 0;
//     int zeroes = 0;
//     for (int right = 0; right < n; right++)
//     {
//         if (arr[right] == 0)
//         {
//             zeroes++;
//         }
//         while (zeroes > k)
//         {
//             if (arr[left] == 0)
//             {
//                 zeroes--;
//             }
//             left++;
//         }
//         ans = max(ans, right - left + 1);
//     }
//     cout << ans << endl;
//     return 0;
// }

// PREFIX SUM+ BINARY SEARCH

#include <bits/stdc++.h>
using namespace std;
int findLastPos(vector<int> &nums, int target, int n)
{
    int left = 0;
    int ans = -1;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
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
    int k;
    cin >> k;
    vector<int> pref(n + 1);
    for (int i = 0; i <= n; i++)
    {

        pref[i + 1] = pref[i] + (arr[i] == 0);
    }
    int low = 0;
    int high = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) // i=l-1
    {
        int pr = k + pref[i];
        int pos = findLastPos(pref, pr, n + 1);
        int windowSize = pos - i;
        // pos-i=>
        //  pos=right i=left-1 => left=i+1
        //  ws=right-left+1
        //  ws=pos-(i+1)+1 => pos-i-1+1 => pos-i
        ans = max(ans, windowSize);
    }
    cout << ans << endl;
    return 0;
}
