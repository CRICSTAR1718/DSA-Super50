#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    int right = n - 1;
    int sumSereja = 0;
    int sumDima = 0;
    bool turn = true;
    while(left<=right)
    {
        int picked = max(arr[left], arr[right]);
        if(picked==arr[left])
        {
            left++;
        }
        else{
            right--;
        }
        if(turn)
        {
            sumSereja += picked;
        }
        else{
            sumDima += picked;
        }
        turn = !turn;
    }
    
    cout << sumSereja << " " << sumDima << endl;
}