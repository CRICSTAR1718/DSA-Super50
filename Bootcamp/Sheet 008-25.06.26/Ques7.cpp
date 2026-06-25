#include <bits/stdc++.h>
using namespace std;
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
    int x;
    cin >> x;
    bool flag = false;
    int count = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        count++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            flag = true;
            break;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (flag)
    {
        cout << count << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}